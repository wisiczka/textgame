
#define MAX_STR_SZ 256
#define MAX_TRAVELABLE_ROOMS 10
#define MAX_ROOMS 10
#define MAX_VERBS 20
#define MAX_NOUNS 20
#define MAX_CONVERSATIONS 20
#define GOD_ID 9999



struct Conversation {
	
	int id;
	char question[50];
	char answer[500];
	int show_inventory;
	int leave_phrase;
	int owner_id;
	
	
	
};



void create_conversation(struct Conversation *conversation, int id, int owner_id, char* question,char* answer, int show_inventory, int leave_phrase);

void create_conversation(struct Conversation *conversation, int id, int owner_id, char* question,char* answer, int show_inventory, int leave_phrase)

{

	
	



	strcpy( conversation->question, question);
	strcpy( conversation->answer, answer);
	conversation->id=id;
	conversation->show_inventory=show_inventory;
	conversation->owner_id=owner_id;
	conversation->leave_phrase = leave_phrase;
	

}



//////////CREATURE

struct Noun {
	char  name[50];
	char adjective1[10];
	char adjective2[10];
	char adjective3[10];
	char post_adjective[10];
	char description[500];
	int happy;
	int noun_id;
	int owner_id;
	int health;
	int position; 
	int wielded; 
	char gender[20];
	char subject_pronoun[16]; 
	char object_pronoun[16]; 
	
	char reflexive_pronoun[21]; 
 //  char ip_pronoun[8];
 //   char dp_pronoun[8];  
	int alive;
	int animate;
	int base_cost;
	int gold;
	int damage;
	int defense;
	int main_quest;

 //  int weight;
  // int size;


};



void create_noun(struct Noun *subject, char* name, int def_happy, int id, int helf, int pos, char* gender, char* subject_pronoun, char* object_pronoun,char* description,
	int base_cost,  int damage,  int defense, int gold);


void create_noun(struct Noun *subject, char* name, int def_happy, int id, int helf, int pos, char* gender, char* subject_pronoun, char* object_pronoun,char* description,
	int base_cost,  int damage,  int defense, int gold)
{




	subject->gold = gold;

	strcpy( subject->name, name);
	strcpy( subject->adjective1, ".");
	subject->happy = def_happy;
	subject->noun_id = id;
	subject->owner_id = GOD_ID;
	subject->wielded = 0;
	subject->health = helf;
	subject->main_quest = 0;
	if (helf>0){subject->alive = 1;subject->animate = 1;}
	if (helf==0){subject->alive = 0;subject->animate = 0;}
	if (helf<0){subject->alive = 0;subject->animate = 1;}



	subject->position = pos;
	strcpy( subject->gender , gender);
	strcpy( subject->subject_pronoun , subject_pronoun);
	strcpy( subject->object_pronoun , object_pronoun);
	strcpy( subject->description, description);
//reflexive pronouns
	char stringy[25];
	strcpy( stringy, subject->object_pronoun);
	strcat(stringy, "self");
 //  printf("%s",stringy);

	strcpy( subject->reflexive_pronoun, stringy);
//reflexive pronouns end

	subject->base_cost = base_cost;
	subject->damage = damage;
	subject->defense = defense;


}










struct Room {
	char  name[50];
	char description[500];
	int position;

	int travelable_rooms[MAX_TRAVELABLE_ROOMS];




};


void create_room(struct Room *room, char*  name,char* description, int position, int travelable_rooms[]);


void create_room(struct Room *room, char*  name,char* description, int position, int travelable_rooms[])
{

	
	int jeep;



	for( jeep  = 0; jeep<MAX_TRAVELABLE_ROOMS; jeep = jeep + 1){
		room->travelable_rooms[jeep]=GOD_ID;
	}
	for( jeep  = 0; jeep<MAX_TRAVELABLE_ROOMS; jeep = jeep + 1){
		room->travelable_rooms[jeep]=travelable_rooms[jeep];
	}





	strcpy( room->name, name);
	strcpy( room->description, description);
	room->position = position;

}




/////////////////////////////VERB FUNCTIONS
////////////////////////////








void headpat(struct Noun *subject , struct Noun *direct_object );
void headpat(struct Noun *subject , struct Noun *direct_object )
{


	if((subject->position == direct_object->position) && (direct_object->animate == 0)){
		printf("%s headpats the %s ! that was interesting .\n", subject->name, direct_object->name);
		subject->happy = (subject->happy) + 10;
	}

	if((subject->position == direct_object->position) && (direct_object->alive == 1) && (direct_object->animate == 1)){
		printf("%s headpats the %s ! %s blushes .\n", subject->name, direct_object->name, direct_object->subject_pronoun );
		direct_object->happy = (direct_object->happy) + 5;
	}

	if((subject->position == direct_object->position) && (direct_object->alive == 0) && (direct_object->animate == 1)){
		printf("%s headpats the %s's dead body ! that was not very pleasant .\n", subject->name, direct_object->name);
		subject->happy = (subject->happy) - 10;
	}
	

}



void examine_noun(struct Noun *subject , struct Noun *direct_object );
void examine_noun(struct Noun *subject , struct Noun *direct_object )
{
	if((subject->position == direct_object->position) || (subject->noun_id == direct_object->owner_id)){
		printf(" %s \n", direct_object->description );

}
}

void examine_room(struct Noun *subject , struct Room *direct_object, struct Noun * nouns,struct Room * rooms  );
void examine_room(struct Noun *subject , struct Room *direct_object,struct Noun * nouns,struct Room * rooms  )
{
	
	int i=0;
	if(subject->position == direct_object->position){
		printf(" %s \n",direct_object->description );
		printf("connections: ");
		for(i =0; (direct_object->travelable_rooms[i] != -2) && (i<MAX_TRAVELABLE_ROOMS); i++ ){
		
			printf(" '%s' ",rooms[direct_object->travelable_rooms[i]].name);
		
		
		
		}
		printf("\n");
		printf("contains: ");
		for( i  = 1; (strcmp(nouns[i].name,"BUFFER NAME")); i = i + 1){

			if( (nouns[i].position == direct_object->position) && (nouns[i].owner_id == GOD_ID)  ){
//            printf("nouns[jeep]->damage %d", nouns[jeep].damage);
				
			if ( !strcmp(nouns[i].adjective1, ".") ){printf(" '%s' ", nouns[i].name);}
	if ( strcmp(nouns[i].adjective1, ".") ){printf(" '%s %s' ",nouns[i].adjective1, nouns[i].name);}


			}


		}
		printf("\n");
	}//else{printf("%s is not in the %s !\n", subject->name, direct_object->name);} removed cause of move merge


}



void move(struct Noun *subject , struct Room *direct_object ,struct Noun * nouns );
void move(struct Noun *subject , struct Room *direct_object ,struct Noun * nouns)
{
	int i=0;
	int jeep =0;
	int lada =0;
	for (i=0; (direct_object->travelable_rooms[i] != -2) && (i<MAX_TRAVELABLE_ROOMS); i++){
	//	printf("%d",i);
	
	if (subject->position == direct_object->travelable_rooms[i]){

	printf("%s moves to the %s  .\n", subject->name, direct_object->name );
	subject->position = direct_object->position;


	for( jeep  = 0; (strcmp(nouns[jeep].name,"BUFFER NAME")); jeep = jeep + 1){

			if(nouns[jeep].owner_id == subject->noun_id){
             nouns[jeep].position = subject->position;


			}


		}
	
	

	}}
	
	
	printf("\n");
}


void inventory(struct Noun *subject,struct Noun * nouns);
void inventory(struct Noun *subject,struct Noun * nouns){
	int jeep;
	
	printf("\n %s has: ", subject->name);
	for( jeep  = 0; (strcmp(nouns[jeep].name,"BUFFER NAME")); jeep = jeep + 1){

			if((nouns[jeep].owner_id == subject->noun_id)){
//            printf("nouns[jeep]->damage %d", nouns[jeep].damage);
			if ( !strcmp(nouns[jeep].adjective1, ".") ){	printf(" '%s' ",nouns[jeep].name);}
			if ( strcmp(nouns[jeep].adjective1, ".") ){	printf(" '%s %s' ",nouns[jeep].adjective1, nouns[jeep].name);}



			}


		}
		printf("\n");
	
	
	
	
}



void take_noun(struct Noun *subject, struct Room *room, struct Noun *direct_object);
void take_noun(struct Noun *subject, struct Room *room, struct Noun *direct_object)
{

	if( (direct_object->position == subject->position) && (direct_object->owner_id == GOD_ID) ){
	if ( strcmp(direct_object->adjective1, ".") ){printf("%s takes the %s %s .\n", subject->name, direct_object->adjective1, direct_object->name);}
	if ( !strcmp(direct_object->adjective1, ".") ){	printf("%s takes the %s .\n", subject->name, direct_object->name);}
		direct_object->owner_id = subject->noun_id;
		
		

	}



}




void drop_noun(struct Noun *subject, struct Room *room, struct Noun *direct_object);
void drop_noun(struct Noun *subject, struct Room *room, struct Noun *direct_object)
{

	if((direct_object->owner_id == subject->noun_id)){
	if ( !strcmp(direct_object->adjective1, ".") ){	printf("%s drops the %s .\n", subject->name, direct_object->name);}
	if ( strcmp(direct_object->adjective1, ".") ){	printf("%s drops the %s %s .\n", subject->name,direct_object->adjective1, direct_object->name);}
		direct_object->owner_id = GOD_ID;
		direct_object->position = subject->position;
		direct_object->wielded = 0;
		

	}else{printf("%s does not have a %s to drop!\n",subject->name, direct_object->name);}



}


void wield_noun(struct Noun *subject, struct Noun *direct_object);
void wield_noun(struct Noun *subject, struct Noun *direct_object)
{
if((direct_object->wielded == 0) && (direct_object->owner_id == subject->noun_id)){
		printf("%s wields the %s .\n", subject->name, direct_object->name);
		direct_object->wielded = 1;
		
	
	}else{printf("%s does not have a %s in their inventory to wield !\n",subject->name, direct_object->name);}



}

void unwield_noun(struct Noun *subject, struct Noun *direct_object);
void unwield_noun(struct Noun *subject, struct Noun *direct_object)
{

if((direct_object->wielded == 1) && (direct_object->owner_id == subject->owner_id)){
		printf("%s unwields the %s .\n", subject->name, direct_object->name);
		direct_object->wielded = 0;

	}else{printf("%s is not currently wielding a %s !\n",subject->name, direct_object->name);}



}


void give_noun(struct Noun *subject, struct Noun *direct_object, struct Noun *indirect_object);
void give_noun(struct Noun *subject, struct Noun *direct_object, struct Noun *indirect_object)
{

	if((subject->position == indirect_object->position) && (direct_object->owner_id == subject->noun_id)){
		printf("%s gives the %s to %s .\n", subject->name, direct_object->name, indirect_object->name);
	///	printf("direct_object->name: %s, indirect_object->name: %s, direct_object->noun_id: %d,indirect_object->noun_id: %d,\n",  direct_object->name, indirect_object->name,direct_object->noun_id,indirect_object->noun_id);
		direct_object->owner_id = indirect_object->noun_id;
		direct_object->wielded = 0;
		
		

	}



}




void buy(struct Noun *subject , struct Noun *direct_object, struct Noun *indirect_object);
void buy(struct Noun *subject , struct Noun *direct_object, struct Noun *indirect_object){
	
	if((subject->position == indirect_object->position) && (subject->gold >= direct_object->base_cost) && (direct_object->owner_id == indirect_object->noun_id)){
		
		
		printf("%s buys the %s from %s for %d gold.\n", subject->name, direct_object->name, indirect_object->name, direct_object->base_cost );
		give_noun(indirect_object,direct_object,subject);
		subject->gold = (subject->gold ) - (direct_object->base_cost);
		indirect_object->gold = (indirect_object->gold ) + (direct_object->base_cost);
		printf("%s now has %d gold . \n", subject->name, subject->gold);
		printf("%s now has %d gold . \n", indirect_object->name, indirect_object->gold);
		
		

	}///else{printf("You cannot buy that here \n");}
		
		
		
	
	
	
	
}


void sell(struct Noun *subject , struct Noun *direct_object , struct Noun *indirect_object );
void sell(struct Noun *subject , struct Noun *direct_object , struct Noun *indirect_object ){
	
	if((subject->position == indirect_object->position) && (indirect_object->gold >= direct_object->base_cost) && (direct_object->owner_id == subject->noun_id)){
		
		
		printf("%s sells the %s to %s for %d gold.\n", subject->name, direct_object->name, indirect_object->name, direct_object->base_cost );
		give_noun(subject,direct_object,indirect_object);
		indirect_object->gold = (indirect_object->gold ) - (direct_object->base_cost);
		subject->gold = (subject->gold) + (direct_object->base_cost);
		printf("%s now has %d gold . \n", subject->name, subject->gold);
		printf("%s now has %d gold . \n", indirect_object->name, indirect_object->gold);
		
		

	}///else{printf("You cannot buy that here \n");}
		
		
		
	
	
	
	
}



///add defense
void attack(struct Noun *subject, struct Noun *direct_object,struct Noun * nouns );
void attack(struct Noun *subject, struct Noun *direct_object,struct Noun * nouns )
{

	int damage = 1;
	int jeep;

	if(subject->position == direct_object->position){
		for( jeep  = 0; (strcmp(nouns[jeep].name,"BUFFER NAME")); jeep = jeep + 1){

			if((nouns[jeep].wielded == 1) &&(nouns[jeep].owner_id == subject->noun_id)){
//            printf("nouns[jeep]->damage %d", nouns[jeep].damage);
				damage = damage + nouns[jeep].damage;


			}


		}
		printf("%s does %d damage to %s .\n", subject->name, damage, direct_object->name);
		direct_object->health = direct_object->health - damage;
		printf(" The %s now has %d health .\n", direct_object->name,  direct_object->health);


	}else{printf("%s is not currently in the same room as %s !\n",subject->name, direct_object->name);}



}












void talk(struct Noun *subject , struct Noun *direct_object ,struct Conversation * conversations, struct Noun * nouns);
void talk(struct Noun *subject , struct Noun *direct_object ,struct Conversation * conversations, struct Noun * nouns){
	
	
	
	int jeep;
	
	int leave = 0;

	if(subject->position == direct_object->position){
		
		printf("%s greets %s\n",subject->name,direct_object->name);
		printf("What would you like to talk about?\n");
		
		
		
		printf("TOPICS: ");
		
		
		for( jeep  = 0; (strcmp(conversations[jeep].question,"BUFFER QUESTION")); jeep = jeep + 1){

			if((conversations[jeep].owner_id == direct_object->noun_id) ){
            printf(" %s ,",  conversations[jeep].question);
				


			}


		}
		
		while(!leave){
			
			char talk_string[MAX_STR_SZ];
	char string_to_parse[MAX_STR_SZ];
	int talk_object = 0;
	char *talk_noun_parse =  0;
		
		printf("\n\n>>>> ");

		fgets(talk_string, MAX_STR_SZ, stdin);
		strcpy(string_to_parse, " ");

		strcat(string_to_parse, talk_string);
		
		
			for( talk_object = 0; (strcmp(conversations[talk_object].question, "BUFFER NAME") && !talk_noun_parse); talk_object = talk_object + 1 ){
				
				talk_noun_parse = strstr(string_to_parse, conversations[talk_object].question);
	//			printf("room_object = %d",room_object);
				



			}talk_object--; ///for second_noun end
			
			
			if(talk_noun_parse){
				
				printf("\n %s: %s\n",direct_object->name,conversations[talk_object].answer);
				if(conversations[talk_object].show_inventory){inventory(&nouns[direct_object->noun_id],nouns);}
				if(conversations[talk_object].leave_phrase){leave = 1;}
				
				
				
			}
	

	}
	
	}
	
	
}