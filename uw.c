
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verbs.h"






void parse(struct Noun * nouns, struct Room * rooms, struct Conversation * conversations,int gamerun,int time);
void removeStringTrailingNewline(char *str) ;




/////////////MAIN MAIN MAIN MAIN MAIN/////////////


void main(void){




	struct Noun nouns[MAX_NOUNS];
	struct Room rooms[MAX_ROOMS];
	struct Conversation conversations[MAX_CONVERSATIONS];



	/// arrays store from which room ids the room can be accessed
	///places u can reach location from, fill empty space with -2
	
	/////     int [MAX_TRAVELABLE_ROOMS] = {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};

	int basement_connections[MAX_TRAVELABLE_ROOMS] = {4,2,3,1,-2,-2,-2,-2,-2,-2};
	int living_room_connections[MAX_TRAVELABLE_ROOMS] = {0,-2,-2,-2,-2,-2,-2,-2,-2,-2};
	int cave_connections[MAX_TRAVELABLE_ROOMS] = {4,3,0,-2,-2,-2,-2,-2,-2,-2};
	int narrow_pathway_connections[MAX_TRAVELABLE_ROOMS] = {2,0,-2,-2,-2,-2,-2,-2,-2,-2};
	int wide_pathway_connections[MAX_TRAVELABLE_ROOMS] = {2,0,-2,-2,-2,-2,-2,-2,-2,-2};
	int pier_market_connections[MAX_TRAVELABLE_ROOMS] = {6,7,-2,-2,-2,-2,-2,-2,-2,-2};
	int shack_connections[MAX_TRAVELABLE_ROOMS] = {5,-2,-2,-2,-2,-2,-2,-2,-2,-2};
	int registration_office_connections[MAX_TRAVELABLE_ROOMS] = {5,-2,-2,-2,-2,-2,-2,-2,-2,-2};
	


	int filler = 0;
	for( filler = 0; (filler < MAX_NOUNS) ; filler++ ){
		create_noun(&nouns[filler], "BUFFER NAME", 99, 992, 910, 90, "BUFFER GENDER", "BUFFER S", "BUFFER S", "BUFFER S", 9100,  95,  991,999);


	}

	for( filler = 0; (filler < MAX_ROOMS) ; filler++ ){
		create_room(&rooms[filler], "BUFFER NAME", "BUFFER DESCRIPTION", 999, basement_connections );


	}
	
	for( filler = 0; (filler < MAX_CONVERSATIONS) ; filler++ ){
		create_conversation(&conversations[filler], 999, GOD_ID, "BUFFER QUESTION", "BUFFER ANSWER", 999 ,0 );


	}


/// create_room(struct Room *room, char*  name,char* description, int position, int travelable_rooms[MAX_TRAVELABLE_ROOMS]);

	create_room(&rooms[0], "basement", "a nice 'basement', decorated with anime posters . there are wooden stairs to the living room. ", 0, basement_connections );
	create_room(&rooms[1], "living room", "the 'living room', there are walls of anime figurine displays . stairs lead down to the basement ", 1, living_room_connections );
	create_room(&rooms[2], "cave", "a dark wet cave with a large pool of water in it. there seem to be somewhat developed pathways leading to other parts of the cave. ", 2, cave_connections );
	create_room(&rooms[3], "narrow pathway", "tight fitting cavern corridors", 3, narrow_pathway_connections );
	create_room(&rooms[4], "wide pathway", "sprawling cavern mouths, seem well traveled", 4, wide_pathway_connections );
	create_room(&rooms[5], "pier market", "the bustling water market", 5, pier_market_connections );
	create_room(&rooms[6], "shack", "a falling apart wooden shack", 6, shack_connections );
	create_room(&rooms[7], "registration office", "you are given written permission to board ships here", 7, registration_office_connections );





////void create_noun(struct Noun *subject, char* name, int def_happy, int id, int helf, int pos, char* gender, char* subject_pronoun, char* object_pronoun,char* description,
///	int base_cost,  int damage,  int defense, int gold);
///single words only

	create_noun(&nouns[0], "anon", 100, 0, 10, 5, "m", "I", "me", "look in the mirror !" , 10000,  1,  1,50);
	create_noun(&nouns[1], "loli", 90, 1, 10, 2, "f", "she", "her", "kawaii oneechan", 1000,  5,  5,10);
	create_noun(&nouns[2], "shota", 90, 2, 10, 2, "m", "he", "him", "a cute boy", 1000,  5,  10,20);
	create_noun(&nouns[3], "katana", 90, 3, 0, 2, "n", "it", "it",  "fine sword", 10,  27,  1,0);
	create_noun(&nouns[4], "kimono", 90, 4, 0, 2, "n", "it", "it", "traditional silk dress", 9,  5,  1,0);
	create_noun(&nouns[5], "terry", 90, 5, 10, 1, "m", "he", "him", "holy c", 1000,  50,  1000,0);
	create_noun(&nouns[6], "seller", 90, 6, 10, 5, "f", "she", "her", "a little girl posing as a merchant. she has an eyepatch and hood covering her hair.", 1000,  17,  13,100);
	create_noun(&nouns[7], "shemagh", 90, 7, 10, 5, "n", "it", "it", "a quality piece of cloth", 3, 0,  2,0);
	take_noun( &nouns[0], &rooms[nouns[0].position], &nouns[7]);
	create_noun(&nouns[8], "dagger", 90, 8, 10, 5, "n", "it", "it", "a small yet dangerous blade", 5, 2,  2,0);
	take_noun( &nouns[6], &rooms[nouns[0].position], &nouns[8]);
	create_noun(&nouns[9], "sabree", 90, 9, 10, 5, "n", "it", "it", "a sharp and hooked western blade", 12, 5,  2,0);
	take_noun( &nouns[6], &rooms[nouns[0].position], &nouns[9]);
	create_noun(&nouns[10], "sabre", 90, 10, 10, 5, "n", "it", "it", "a sabre of exceptionally high quality", 20, 8,  4,0);
 strcpy( nouns[10].adjective1, "fine");
 //take_noun( &nouns[6], &rooms[nouns[0].position], &nouns[10]);

 	create_noun(&nouns[11], "sabre", 90, 11, 10, 5, "n", "it", "it", "a rare sabre crafted from silver", 20, 8,  4,0);
 strcpy( nouns[11].adjective1, "silver");
 






	create_conversation(&conversations[0], 0,6, "trading", "looking to trade are you? better not steal anything... ", 1,1  );
	create_conversation(&conversations[1], 1,6, "weather", "pretty stormy today, wouldn't want to be the one setting out this afternoon ", 0 ,0 );
	create_conversation(&conversations[2],2,6, "leave", "bye bye !", 0,1);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









	int gamerun =1; 
	int time =0;
	





 //static const char *nouns[] = { " candy", " meowni", " shirt", " skirt", "", "", "", "", "", ""};


	////////////////// GAME INTROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO



///	printf("You are in line to board a submarine. It is a refitted Ohio class SSBN that now functions primarily as a research vessel in the Arctic.\n");printf("The person in front of you has just finished being checked by the greeter, and you walk up to him. \n");printf("Following a cheery hello, the gray haired gentleman asks you for your name.\n")	printf("Ah wonderful ! Please come inside. The man says. \n");	printf("You board the ship and after a few ladders and stairs find yourself in the mess hall which has been converted into a fairly presentable dining room. \n");	printf("");
	
	
	printf("You are standing in the middle of the pier market. You have a ship to catch\n\n");



	while (gamerun) {




		time++;

		parse(nouns, rooms,conversations, gamerun,time);




	}}


	void parse(struct Noun * nouns, struct Room * rooms, struct Conversation * conversations, int gamerun,int time){
		






		char comm[MAX_STR_SZ];
		char string_to_parse[MAX_STR_SZ];



		
		
		
		char *room_noun_parse;
		
		
	
		char tokenized_parse[20][20];


		
		int room_object = 0;
		int statcounter = 0;
		int tokencounter =0;

		
		room_noun_parse = 0;
		

		
	

	

		static const char *verbs[] = { "pat", "tickle", "kill", "dev", "examine", "go", "take", "drop", "wield", "unwield", "attack", "give", "move", "wear", "inventory", "buy", "sell", "talk", "BUFFER NAME"};
		static const char *prepositions[] = { "to", "from", "BUFFER NAME" };




		printf(">>> ");

		fgets(comm, MAX_STR_SZ, stdin);

 //        scanf("%s", comm);  // Note: %s is for char arrays and not %f(floats)


		strcpy(string_to_parse, " ");

		strcat(string_to_parse, comm);

///TOKENIZATION
		char * token = strtok(comm, " ");
   // loop through the string to extract all other tokens
		for(tokencounter=0; token != NULL ; tokencounter++) {

			strcpy(tokenized_parse[tokencounter], token);
			removeStringTrailingNewline(tokenized_parse[tokencounter]);

		///	printf("token %d  = %s \n",tokencounter,tokenized_parse[tokencounter]);
			token = strtok(NULL, " ");
		}

   ///TOKENIZATION END

		int i = 0;
		
		int noun1_parse = -1;
		int noun1_counter = -1;
		int noun2_parse = -1;
		int second_noun = -1;
		int	verb_parse = -1; /// NULL POINTER
		int verb = -1;
		int direct_object_noun = -1;
		int indirect_object_noun = -1;
		int noun1_hit = -1;
		int noun2_hit = -1;
		int subject_noun = 0;
		


for( i = 0; ((i < tokencounter)) ; i++){
 
 	if(verb_parse){

		for( verb = 0;(strcmp(verbs[verb], "BUFFER NAME") && verb_parse); verb = verb + 1 ){
			verb_parse = strcmp(tokenized_parse[i], verbs[verb]);

		//	printf("verb parse: %d", verb_parse);



	//    printf("string_to_parse = %s, \n",string_to_parse);

		 }verb--; /// for verb

		}


				
				
				
				


			if (!noun1_parse && noun2_parse){


				for( second_noun = 0; (strcmp(nouns[second_noun].name, "BUFFER NAME") && noun2_parse); second_noun = second_noun + 1 ){
		 	noun2_parse = strcmp(tokenized_parse[i], nouns[second_noun].name);
		 	
		 	



			}second_noun--; ///for second_noun end





			}

			if (noun1_parse){

			 for( noun1_counter = 0; (strcmp(nouns[noun1_counter].name, "BUFFER NAME") && noun1_parse ); noun1_counter = noun1_counter + 1 ){
		 	noun1_parse = strcmp(tokenized_parse[i], nouns[noun1_counter].name);
		 

int truthh = 0;
	truthh = (nouns[subject_noun].position == nouns[noun1_counter].position) ;  ///not special case
	if (!(strcmp(verbs[verb], "drop"))){ truthh = (   (nouns[subject_noun].noun_id == nouns[noun1_counter].owner_id) &&  (nouns[subject_noun].position == nouns[noun1_counter].position) ) ;}  ///drop
	if (!(strcmp(verbs[verb], "take"))){ truthh = (   (GOD_ID == nouns[noun1_counter].owner_id) &&  (nouns[subject_noun].position == nouns[noun1_counter].position)  ) ;}  ///take




			if (!noun1_parse && (noun1_hit==-1) && truthh){
				noun1_parse = 1;
	//			printf("noun1hithithit\n");
				noun1_hit = noun1_counter;
				
				if (!strcmp(tokenized_parse[i-1], nouns[noun1_counter].adjective1)){
	///				printf("adjective1hithithit\n");

					noun1_parse=0;

		 		 
}

		 										
		 										}

		 		if (!noun1_parse && (noun1_hit!=-1) && truthh ){
		 			noun1_parse =1;
			
				if (!strcmp(tokenized_parse[i-1], nouns[noun1_counter].adjective1)){


					noun1_hit=noun1_counter;

		 		 
}

		 										
		 										}	noun1_parse = 1;


		 	
	///printf("truth: %d \n", truthh);printf("noun1_hit = %d  noun1_counter = %d \n", noun1_hit, noun1_counter);printf(" %s SET AS INDIRECT OBJECT \n %s SET AS DIRECT OBJECT \n",nouns[noun1_hit].name, nouns[second_noun].name);printf("comm = %s, \n",comm);
}

			
		}





}






///

int prepositioned_noun_parse = -1;
int preposition = 0;
		int preposition_parse = 1;





		for( i = 0; ((i < tokencounter) && preposition_parse) ; i++){
	//		printf("token2 %d  = %s \n",i,tokenized_parse[i]);
			for (preposition=0;(strcmp(prepositions[preposition], "BUFFER NAME") && preposition_parse); preposition=preposition+1){


				preposition_parse = (strcmp(prepositions[preposition], tokenized_parse[i]));
	//			printf("preposition_parse = %d \n prepositions[preposition] = %s \n tokenized_parse[i] = %s \n",preposition_parse, prepositions[preposition],tokenized_parse[i]);
				

			}
		}i--;

int x = i;
int prepositioned_noun = 0;
if (preposition_parse == 0){
	for( x=i ; ((x < tokencounter) && prepositioned_noun_parse) ; x++ ){

					for( prepositioned_noun = 0; (strcmp(nouns[prepositioned_noun].name, "BUFFER NAME") && prepositioned_noun_parse); prepositioned_noun = prepositioned_noun + 1 ){

						


					
//							 printf("noun1_parse = %d \n nouns[noun1_counter].name = .%s. \n tokenized_parse[%d] = .%s. \n",noun1_parse, nouns[noun1_counter].name,x,tokenized_parse[x]);
		 	   prepositioned_noun_parse = strcmp(nouns[prepositioned_noun].name, tokenized_parse[x]);
		 	   
		 

		 }
		 	
		 	



			}




				}prepositioned_noun--;
				
	///printf("AAAA %s SET AS SECOND NOUN \n %s SET AS FIRST NOUN  \n  %s SET AS PREPOSITIONED\n\n",nouns[second_noun].name, nouns[noun1_counter].name, nouns[prepositioned_noun].name);
	
	
	

if( noun2_parse){direct_object_noun=noun1_hit;}
if( !noun2_parse){direct_object_noun=noun1_hit; indirect_object_noun=second_noun;}



	/// CLASS A VERBS: SECOND NOUN IS DIRECT OBJECT, PREPOSITIONED NOUN IS INDIRECT OBJECT
	
	
	if (!(strcmp(verbs[verb], "give")) || !(strcmp(verbs[verb], "sell"))){
		
		
		if( !noun2_parse){direct_object_noun=second_noun; indirect_object_noun=noun1_hit;}		
		
		
		if(!prepositioned_noun_parse ){
						indirect_object_noun = prepositioned_noun;
						if(prepositioned_noun==noun1_hit){direct_object_noun = second_noun;}
						if(prepositioned_noun==second_noun){direct_object_noun = noun1_hit;}


					}		

		 	   }
			   
			   
			   
			 /// CLASS B VERBS: FIRST NOUN IS DIRECT OBJECT, PREPOSITIONED NOUN IS INDIRECT OBJECT
	
	
	if (!(strcmp(verbs[verb], "buy"))){
		
		

		
		
		if(!prepositioned_noun_parse ){
						indirect_object_noun = prepositioned_noun;
						if(prepositioned_noun==noun1_hit){direct_object_noun = second_noun;}
						if(prepositioned_noun==second_noun){direct_object_noun = noun1_hit;}


					}		

		 	   }  
			   
			   
			   
			   
			   
				
				
///printf("BBB %s SET AS DIRECT OBJECT NOUN \n %s SET AS INDIRECT OBJECT NOUN  \n  %s SET AS PREPOSITIONED\n\n",nouns[direct_object_noun].name, nouns[indirect_object_noun].name, nouns[prepositioned_noun].name);				


		 


////printf(" %s SET AS INDIRECT OBJECT \n %s SET AS DIRECT OBJECT \n",nouns[noun1_hit].name, nouns[second_noun].name);




	



			for( room_object = 0; (strcmp(rooms[room_object].name, "BUFFER NAME") && !room_noun_parse); room_object = room_object + 1 ){
				
				room_noun_parse = strstr(string_to_parse, rooms[room_object].name);
	//			printf("room_object = %d",room_object);
				



			}room_object--; ///for second_noun end


//		printf("verb = %d indirect object = %d direct object = %d",verb,noun1_hit,second_noun);

 ///parse match events

			if (!verb_parse ){
				
				
			if (!(strcmp(verbs[verb], "inventory"))){
						inventory(&nouns[0], nouns);


					}				
				
				
				
				
				
  ///           printf("MEOW\n");
				

	if ( room_noun_parse){//printf("WAHTTHEHECK %d %d %s",room_object, verb, verbs[verb] );

				if ((!(strcmp(verbs[verb], "examine"))) && room_noun_parse){
					examine_room(&nouns[0], &rooms[room_object], nouns,rooms);
		 //           printf("Tss ~\n");

				}

				if (!(strcmp(verbs[verb], "go")) || !(strcmp(verbs[verb], "move"))){
					
					

					move(&nouns[0], &rooms[room_object],nouns);
					examine_room(&nouns[0], &rooms[room_object],nouns,rooms);
					
		// BUFFER NAME			
	 //               printf("Tss ~\n");

				}




			}
				


////	static const char *verbs[] = { " pat", " tickle", " kill", " dev", " examine", " go", " take", " drop", " wield", " unwield", " attack", "BUFFER NAME", ""};
				if (noun1_parse>=0 ){

					if (!(strcmp(verbs[verb], "pat"))){
						headpat(&nouns[0], &nouns[noun1_hit]);


					}
					if (!(strcmp(verbs[verb], "talk"))){
						talk(&nouns[0], &nouns[noun1_hit],conversations, nouns);


					}

					if (!(strcmp(verbs[verb], "kill"))){
						printf("You kill the loli . Fun .\n");
						gamerun = 0;
					}

					if (!(strcmp(verbs[verb], "dev"))){
						printf("happy = %i, verbs[1] = %s, \n",nouns[1].happy, verbs[1]);
						printf("nouns[second_noun].name = %s, \n",nouns[second_noun].name);
						printf(" rooms[0].name %s rooms[0].description %s ! rooms[0].travelable_rooms[1] %d  .\n", rooms[0].name, rooms[0].description, rooms[0].travelable_rooms[1] );
						nouns[1].happy = nouns[1].happy + 10;

					}

					if (!(strcmp(verbs[verb], "examine"))&& noun2_parse){
						examine_noun(&nouns[0], &nouns[noun1_hit]);

					}

					

					

					if (!(strcmp(verbs[verb], "take"))){
				///		printf("noun1_hit = %d  noun1_counter = %d", noun1_hit, noun1_counter);
						
						take_noun( &nouns[0], &rooms[nouns[0].position], &nouns[noun1_hit]);

					}

					if (!(strcmp(verbs[verb], "drop"))){

						drop_noun( &nouns[0], &rooms[nouns[0].position], &nouns[noun1_hit]);

					}
					if (!(strcmp(verbs[verb], "wield")) || !(strcmp(verbs[verb], "wear"))){

						wield_noun( &nouns[0],  &nouns[noun1_hit]);

					}
					if (!(strcmp(verbs[verb], "unwield"))){

						unwield_noun( &nouns[0],  &nouns[noun1_hit]);

					}

					if (!(strcmp(verbs[verb], "attack"))){

						attack(&nouns[0], &nouns[noun1_hit], nouns);

					}

					if (!(strcmp(verbs[verb], "give"))){

						give_noun(&nouns[0], &nouns[direct_object_noun], &nouns[indirect_object_noun]);

					}
					
					if (!(strcmp(verbs[verb], "buy"))){

						buy(&nouns[0], &nouns[direct_object_noun], &nouns[indirect_object_noun]);

					}
					
					if (!(strcmp(verbs[verb], "sell"))){

						sell(&nouns[0], &nouns[direct_object_noun], &nouns[indirect_object_noun]);

					}



			}  /// if  noun parse end

		



	} ///if verb parse end



	for( statcounter = 0;(strcmp(nouns[statcounter].name,"BUFFER NAME")); statcounter = statcounter + 1 ){

			///stat events

		if ( (nouns[statcounter].health < 0 ) && (nouns[statcounter].alive == 1)){

			printf("%s has died !\n",nouns[statcounter].name);
			nouns[statcounter].alive = 0;

		}

	   }  ///for stat events


	if (nouns[0].main_quest == 0){
		
		
	///	printf("nyaa");
		
		
		
	}





	}//// parse function declaration end








	void removeStringTrailingNewline(char *str) {
  if (str == NULL)
    return;
  int length = strlen(str);
  if ((str[length-1] == '\n') || (str[length-1] == '\n'))
    str[length-1]  = '\0';
}

