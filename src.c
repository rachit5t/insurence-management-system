/*Including library header files for using in this program*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/*Declaring functions to be used in this program*/
void user_signup();
void user_signin();
int user_interface();
void admin_login();
int admin_interface();
void Exit();






/*This is the first menu shown to the user after he/she opens the application.
 And this will send users to other function according to the option they choose */
 
void main(){
	int repeat;
	char main_menu_choose;
	printf("Welcome To ZeeMediLife Insurance\n");
	printf("---------------------------------\n");
	printf("Please select Your desired option \n");
	printf("1. Create an new user account \n");
	printf("2. Sign in using existing user account \n");
	printf("3. Admin login\n");
	printf("4. Exit \n\n");
	printf("Input ==> ");
	scanf("%s", &main_menu_choose);
	switch (main_menu_choose){
		case '1' :{
			user_signup();
			break;
		}
		case '2' :{
			user_signin();
			break;
		}	
		case '3' :{
			admin_login();
			break;
		}	
		case '4' :{
			Exit();
			break;
		}	
		default:{
			system("cls"); 
			printf("Please Select an Valid Input\n");
			printf("///////////////////////////////\n\n");
			main();
			break;
		}	
}
}













/*This function asks details from user, print plans available according to 
their age and creates a user account. Then it sends user to user Signup menu.*/

void user_signup(){
	char plan[30];
	char username[30];
	char type [30];
	char password[30];
	int line_count;
	char phone_number[30];
	int user_id;
	char counting;
	char date[30] = "No_Claim_Till_now"; 
	long int remaining_claim;
	FILE*user_data;
	int age;
	system("cls");
	printf("User signup\n");
	printf("-----------------------------\n");
	printf("Inter your age ==> ");
	
	scanf("%d", &age);
	
	/* printing speific plans according to the age given*/ 
	
	if(age < 21) {
		plan_120:
		printf("\t\t\tplan 120(RM) \t plan150(RM) \t plan200(RM) \n");
		printf("Monthly premium \t 120 \t\t 150 \t\t 200\n");
		printf("Annual claim limit \t 120000 \t 150000 \t 200000\n");
		printf("Lifetime claim limit \t 600,000 \t 750000 \t 1000000\n\n");
		printf("Types Of claim\tEligblity Amount\n");
		printf("\t\tPlan 120\tPlan 150 \tPlan 200\n");
		printf("Room Charges\t120 per day\t150 per day\t200 per day\n");
		printf("Icu Charges\t250 per day\t400 per day\t700 per day\n");
		printf("Other Charges\tTo be Aproved By Zeemedilife\n");
		
		
		
		printf("\nType Your plan (120 / 150 / 200) ==> ");
		scanf("%s",&plan);
		if (strcmp(plan, "120") !=0){
			if (strcmp(plan, "150") !=0){
				if (strcmp(plan, "200") !=0){
				system("cls");
				printf("///////////////////////////////////// \n");
				printf("The plan you typed doesnot exist!!!\n");
				printf("Please choose an valid plan\n");
				printf("///////////////////////////////////// \n \n");
				goto plan_120;
				}
				}
				}
			
		
}else if(age < 41){
	plan_150:
	printf("\t\t\t plan150(RM) \t plan200(RM) \n");
	printf("Monthly premium \t 150 \t\t 200\n");
	printf("Annual claim limit \t 150000 \t 200000\n");
	printf("Lifetime claim limit \t 750000 \t 1000000\n\n");
	
	printf("Types Of claim\tEligblity Amount\n");
		printf("\t\tPlan 150 \tPlan 200\n");
		printf("Room Charges\t150 per day\t200 per day\n");
		printf("Icu Charges\t400 per day\t700 per day\n");
		printf("Other Charges\tTo be Aproved By Zeemedilife\n");
		printf("\nType Your plan (150 / 200) ==> ");
	scanf("%s",&plan);
		if (strcmp(plan, "150") != 0){
			if (strcmp(plan, "200") != 0){
				system("cls");
				printf("///////////////////////////////////// \n");
				printf("The plan you typed doesnot exist!!!\n");
				printf("Please choose an valid plan\n");
				printf("///////////////////////////////////// \n \n");
				goto plan_150;
			}
		}
}else if(age < 55){
	plan_200:
	printf("\t\t\t plan200(RM) \n");
	printf("Monthly premium \t 200\n");
	printf("Annual claim limit \t 200000\n");
	printf("Lifetime claim limit \t 1000000\n\n");
	
	printf("Types Of claim\tEligblity Amount\n");
		printf("\t\tPlan 200\n");
		printf("Room Charges\t200 per day\n");
		printf("Icu Charges\t700 per day\n");
		printf("Other Charges\tTo be Aproved By Zeemedilife\n");
		printf("\nType Your plan (200) ==> ");
	scanf("%s",&plan);
		if (strcmp(plan, "200") != 0){
				system("cls");
				printf("///////////////////////////////////// \n");
				printf("The plan you typed doesnot exist!!!\n");
				printf("Please choose an valid plan\n");
				printf("///////////////////////////////////// \n \n");
				goto plan_200;
			}
		} else{
			printf("Sorry We dont have Plan for users above 54\n");
			main();
		}
	printf("Create an username ==> ");
	
	scanf("%s", &username);
	annual_lifetime:
	printf("annual or lifetime ==> ");
	scanf("%s", &type);
	

	if (strcmp(type, "annual") != 0 && strcmp(type, "lifetime") != 0){
		system("cls");
		printf("///////////////////////////////////// \n");
				printf("The plan you typed doesnot exist!!!\n");
				printf("Please choose an valid plan\n");
				printf("///////////////////////////////////// \n \n");
		goto annual_lifetime;
		
	}
	
	/* setting claim limit as per the plan subscribed*/
	
	if (strcmp(plan, "120") ==0 && strcmp(type, "annual") ==0){
		remaining_claim = 120000;
	}else if (strcmp(plan, "120") ==0 && strcmp(type, "lifetime") ==0){
		remaining_claim = 600000;
	}else if (strcmp(plan, "150") ==0 && strcmp(type, "annual") ==0){
		remaining_claim = 150000;
	}else if (strcmp(plan, "150") ==0 && strcmp(type, "lifetime") ==0){
		remaining_claim = 750000;
	}else if (strcmp(plan, "200") ==0 && strcmp(type, "annual") ==0){
		remaining_claim = 200000;
	}else if (strcmp(plan, "200") ==0 && strcmp(type, "lifetime") ==0){
		remaining_claim = 1000000;
	}
	
/* user_id generator . it uses the number of lines written in the file to generate user id in order*/	
	user_data = fopen("User_data.txt","r");
	for (counting = getc(user_data); counting != EOF; counting = getc(user_data)){
	
        if (counting == '\n'){
            line_count = line_count + 1;
            }
            }
            
            user_id = line_count + 153430000;  
  fclose(user_data);
  printf("Create an password for your account ==> ");
  scanf("%s", &password);
  printf("Type Your Phone number ==> ");
  scanf("%s", &phone_number);
  
/*writing the user details in a file to read it later*/

	user_data = fopen("User_data.txt","a");
	fprintf(user_data,"%d %s %s %d %s %s %d %s %s\n", user_id, username, password, age, plan, type, remaining_claim, phone_number,date);
	fclose(user_data);
	system("cls");
	printf("\n \n----------------------------------------------\n");
	printf("Sucessfully created your account \n");
	printf("----------------------------------------------\n\n");
	printf("Remember this credencials for login\n");
	printf("User Id ==> %d\n", user_id);
	printf("password ==> %s\n",password);
	printf("\n\nPlease login using your credencials............\n\n");
	user_signin();
	}


















/*This Function ask for user id and password and if the id 
and password are correct it send then to user interface. */

void user_signin(){
	FILE*user_data;
	FILE *rewrite_data;
	char usr_id[30];
	char usr_password[30];
	char read_id[30];
	char read_username[30];
	char read_password[30];
	char read_age[30];
	char read_plan[30];
	char read_type[30];
	char read_claim[30];
	char phone_number[30];
	char claimed_date[30];
	usr_sign_in:
	printf("---------------------------------\n");
	printf("User signin\n");
	printf("---------------------------------\n\n\n");
	printf("Please type Your User id ==> ");
	scanf("%s", &usr_id);
	printf("Please type your password ==> ");
	scanf("%s", &usr_password);
	
	/*searching for the user given id and password in the file*/
	
	user_data = fopen("User_data.txt","r");
	while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s",read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number,claimed_date) == 9){
		if (strcmp(usr_id, read_id) == 0){
			if (strcmp(usr_password, read_password) == 0){
				fclose(user_data);
				user_interface(read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number, claimed_date);
				
		}
		}
			
	}
	printf("\nEither Password Or User Id was wrong. Please try again in 5 seconds ..........\n");
	fclose(user_data);
	sleep(5);
	system("cls");
	goto usr_sign_in;
}











/*This Function allows user to print their details, 
submit claim and also print their plan type and limits. */

int user_interface(read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number, claimed_date){
	FILE*user_data;
	char write_id[30];
	char write_username[30];
	char write_password[30];
	char write_age[30];
	char write_plan[30];
	char write_type[30];
	char write_claim[30];
	char phon_number[30];
	int insuffecient;
	int choose_menu;
	int room_charge;
	int icu_charge;
	int total_claim;
	int other_charge;
	char claim_date[30];
	int read_claim_int;
	read_claim = atoi(read_claim);
	system("cls");
	choose_mennu:
	printf("-------------------------------\n");
	printf("User Interface\n");
	printf("-------------------------------\n\n");
	printf("Welcome %s.\nYou can choose what you want to do from here ......\n",read_username);
	printf("1. Print My details\n");
	printf("2. Submit Claim\n");
	printf("3. See my claim limit\n");
	printf("4. Exit to main menu\n\n\n");
	printf("input ==> ");
		
	scanf("%d", &choose_menu);
	switch (choose_menu){
		case 1 :{
			/* printing user details*/
			
			system("cls");
			printf("Your Id ==> %s\nYour Name ==> %s\n",read_id,read_username);
			printf("Your Password ==> %s\nYour Age ==> %s\n",read_password,read_age);
			printf("Plan ==> %s\nType ==> %s\n",read_plan,read_type);
			printf("Remaining Claim ==> %d\n",read_claim);
			printf("Phone Number ==> %s\n", phone_number);
			printf("Last Claimed Date ==> %s\n\n\n",claimed_date);
			
			goto choose_mennu;
			break;
		}
		case 2 :{
			/* processing claim*/
			system("cls");
			printf("Claim Room Charges For How many days ?  ==> ");
			scanf("%d", &room_charge); 
			printf("Claim Icu Charges For How many days ?  ==> ");
			scanf("%d", &icu_charge);
			printf("How much Amount To claim For other Charges ?  ==> ");
			scanf("%d", &other_charge);
			if (strcmp(read_plan,"120") == 0){
				room_charge = room_charge * 120;
				icu_charge = icu_charge * 250;
				
			}else if (strcmp(read_plan,"150") == 0){
				room_charge = room_charge * 150;
				icu_charge = icu_charge * 400;
			}else if (strcmp(read_plan,"200") == 0){
				room_charge = room_charge * 200;
				icu_charge = icu_charge * 700;
			}
			total_claim = room_charge + icu_charge + other_charge;
			read_claim_int = read_claim;
			if (total_claim <= read_claim_int){
				
				read_claim_int = read_claim_int - total_claim;
				printf("Congratulation Your claim was accepted\n");
				user_data = fopen("User_data.txt","r");
				
				/* updating user remaining balance*/
				
				FILE*rewrite_data;
				rewrite_data = fopen("rewrite_data.txt","w");
				while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", write_id, write_username, write_password, write_age, write_plan, write_type, write_claim, phon_number, claim_date) == 9){
					if (strcmp(write_id,read_id) == 0 && strcmp(write_password,read_password) == 0){
						/* Getting Time For claim history*/
						time_t tim;
						tim = time(NULL);
						strftime(claim_date, sizeof(claim_date), "%Y:%m:%d", localtime(&tim));
						
						fprintf(rewrite_data,"%s %s %s %s %s %s %d %s %s\n", write_id, write_username, write_password, write_age, write_plan, write_type, read_claim_int, phon_number,claim_date);
						
					}else{
						fprintf(rewrite_data,"%s %s %s %s %s %s %s %s %s\n", write_id, write_username, write_password, write_age, write_plan, write_type, write_claim, phon_number, claim_date);
						
						
					}
				}
				fclose(rewrite_data);
				fclose(user_data);
				remove("User_data.txt");
				rename("rewrite_data.txt","User_data.txt");
				read_claim = read_claim_int;
				claimed_date = claim_date;
				
				
				
				
				goto choose_mennu;
			}else{
				insuffecient = total_claim - read_claim_int;
				printf("You dont have enough balance. you need to have %d more balance then you have now..\n");
				goto choose_mennu;
			}
			break;
		}
		case 3 :{
			/*printing the user claim details*/
			if (strcmp(read_plan,"120") == 0){
				system("cls");
				printf("Types Of claim\tEligiblaty amount\n");
				printf("Room charges\t120 per day\n");
				printf("Icu Charges\t250 per day\n");
				printf("other charges\tapproved by zeemedilife\n");
			}else if (strcmp(read_plan,"150") == 0){
				system("cls");
				printf("Types Of claim\tEligiblaty amount\n");
				printf("Room charges\t150 per day\n");
				printf("Icu Charges\t400 per day\n");
				printf("other charges\tapproved by zeemedilife\n");
			}else if (strcmp(read_plan,"200") == 0){
				system("cls");
				printf("Types Of claim\tEligiblaty amount\n");
				printf("Room charges\t200 per day\n");
				printf("Icu Charges\t700 per day\n");
				printf("other charges\tapproved by zeemedilife\n");
			}
			
			printf("\n\nYour remaining claim limit is %d\n\n\n",read_claim);
			goto choose_mennu;
			break;
		}
		case 4 :{
			system("cls");
			main();
			break;
		}
		default :{
			printf("Please Type valid input.....\n");
			sleep(10);
			goto choose_mennu;
			break;
		}
	}
}















/* This function asks for admin username and password. If the
 password and username is correct it sends them to admin interface.*/

void admin_login(){
	char admin_username [20];
	char admin_password [20];
	system("cls");
	printf("Admin Login\n");
	printf("------------------------------------------------\n");
	printf("Please type exit anytime To go back in main menu\n");
	printf("Admin username ==> ");
	scanf("%s", &admin_username);
	if (strcmp(admin_username, "exit") == 0){
		system("cls");
		main();
	}
	printf("Admin password ==> ");
	scanf("%s", &admin_password);
	if (strcmp(admin_password, "exit") == 0){
		system("cls");
		main();
	}
	
	/*checking id and password*/
	if (strcmp(admin_username, "zeemedilife") == 0 && strcmp(admin_password, "zeemedi12") == 0){
		admin_interface();
	}else{
		system("cls");
		printf("Either your username or password is incorrect\n");
		printf("///////////////////////////////////////////////\n\n");
		printf("Please retry in 5 seconds....");
		sleep(5);
		admin_login();
	}
}

































/* This function has search tools for admin. Admin can search
 any user using id, plan, claim type, age. and can also print
  total number of annual or lifetime subscribers with the number
   of people who have exhausted their claim limit.*/
   
int admin_interface(){
	
	FILE*user_data;
	char usr_id[30];
	char usr_age[30];
	char usr_plan[30];
	char usr_type[30];
	char read_id[30];
	int total_subscribers;
	int exhausted_subscribers = 0;
	char read_username[30];
	char read_password[30];
	char read_age[30];
	char read_plan[30];
	char read_type[30];
	char phone_number[30];
	char read_claim[30];
	char claimed_date[30];
	int admin_choose;
	int total_claimed;
	system("cls");
	admin_startt:
	printf("--------------------------------\n");
	printf("Admin Interface\n");
	printf("--------------------------------\n\n");
	printf("Choose What You want To do\n");
	printf("1. Search User Details By ID\n");
	printf("2. Search Users By Plan\n");
	printf("3. Search Users By Claim Type\n");
	printf("4. Search Users By Age\n");
	printf("5. Accounts information\n");
	printf("6. Exit To main Menu\n");
	printf("Input ==> ");
	scanf("%d",&admin_choose);
	
	switch (admin_choose){
		case 1 :{
			/* search details by userid*/
			printf("Please type An User id ==> ");
			scanf("%s", &usr_id);
			user_data = fopen("User_data.txt","r");
			while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", &read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number, claimed_date) == 9){
				if (strcmp(usr_id, read_id) == 0){
					system("cls");
					printf("Id ==> %s\nName ==> %s\n",read_id,read_username);
					printf("Password ==> %s\nAge ==> %s\n",read_password,read_age);
					printf("Plan ==> %s\nType ==> %s\n",read_plan,read_type);
					printf("Remaining Claim ==> %s\n",read_claim);
					printf("Phone Number ==> %s\n",phone_number);
					printf("Last Claimed Date ==> %s\n\n\n",claimed_date);
					goto admin_startt;
					
					
				}
				
			
			}
			fclose(user_data);
			goto admin_startt;
			break;
		}
		case 2 :{
			/* search details by plan*/
			case_2:
			printf("Which plan To Search for ?\n");
			printf("120 / 150 / 200 ==> ");
			scanf("%s", &usr_plan);
			system("cls");
			if (strcmp(usr_plan, "120") == 0 || strcmp(usr_plan, "150") == 0 || strcmp(usr_plan, "200") == 0){
				user_data = fopen("User_data.txt","r");
				while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", &read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number, claimed_date) == 9){
					if (strcmp(usr_plan,read_plan) == 0){
						printf("Id ==> %s\nName ==> %s\n",read_id,read_username);
						printf("Password ==> %s\nAge ==> %s\n",read_password,read_age);
						printf("Plan ==> %s\nType ==> %s\n",read_plan,read_type);
						printf("Remaining Claim ==> %s\n",read_claim);
						printf("Phone Number ==> %s\n",phone_number);
						printf("Last Claimed Date ==> %s\n\n\n",claimed_date);
					
					}
				
			
				}
			}else{
				printf("Invalid input....\n");
				goto case_2;
			}
			fclose(user_data);
			goto admin_startt;
			break;
			
		
		}
		case 3 :{
			/* search details by claim type*/
			case_3:
			printf("Which plan To Search for ?\n");
			printf("annual / lifetime ==> ");
			scanf("%s", &usr_type);
			system("cls");
			if (strcmp(usr_type, "annual") == 0 || strcmp(usr_type, "lifetime") == 0){
				user_data = fopen("User_data.txt","r");
				while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", &read_id, read_username, read_password, read_age, read_plan, read_type,read_claim, phone_number, claimed_date) == 9){
					if (strcmp(usr_type,read_type) == 0){
						printf("Id ==> %s\nName ==> %s\n",read_id,read_username);
						printf("Password ==> %s\nAge ==> %s\n",read_password,read_age);
						printf("Plan ==> %s\nType ==> %s\n",read_plan,read_type);
						printf("Remaining Claim ==> %s\n",read_claim);
						printf("Phone Number ==> %s\n",phone_number);
						printf("Last Claimed Date ==> %s\n\n\n",claimed_date);
					
					}
				
			
				}
			}else{
				printf("Invalid input....\n");
				goto case_3;
			}
			fclose(user_data);
			goto admin_startt;
			break;
		}
		case 4 :{
			/* search details by age*/
			case_4:
			printf("Type age ==> ");
			scanf("%s", &usr_age);
			system("cls");
				user_data = fopen("User_data.txt","r");
				while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", &read_id, read_username, read_password, read_age, read_plan, read_type,read_claim, phone_number, claimed_date) == 9){
					if (strcmp(usr_age,read_age) == 0){
						printf("Id ==> %s\nName ==> %s\n",read_id,read_username);
						printf("Password ==> %s\nAge ==> %s\n",read_password,read_age);
						printf("Plan ==> %s\nType ==> %s\n",read_plan,read_type);
						printf("Remaining Claim ==> %s\n",read_claim);
						printf("Phone Number ==> %s\n",phone_number);
						printf("Last Claimed Date ==> %s\n\n\n",claimed_date);
					
					}
				
			}
			fclose(user_data);
			goto admin_startt;
			break;
		}
		case 5:{
			/*print accounts information*/
			system("cls");
			strcpy(usr_type, "annual");
			user_data = fopen("User_data.txt","r");
			total_subscribers = 0;
			exhausted_subscribers = 0;
			while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number, claimed_date) == 9){
				if (strcmp(usr_type, read_type) == 0){
					total_subscribers = total_subscribers + 1;
					if (strcmp(read_claim,"0") == 0){
						exhausted_subscribers = exhausted_subscribers + 1;
					}
					
					
		}
	}
			fclose(user_data);
			printf("Annual Subscribers\n");
			printf("-------------------\n");
			printf("Total Subscribers ==> %d\n",total_subscribers);
			printf("Subscribers who have exhausted their claim limit ==> %d\n",exhausted_subscribers);	
			total_subscribers = 0;
			exhausted_subscribers = 0;
			strcpy(usr_type, "lifetime");
			user_data = fopen("User_data.txt","r");
			while(fscanf(user_data, "%s %s %s %s %s %s %s %s %s", read_id, read_username, read_password, read_age, read_plan, read_type, read_claim, phone_number, claimed_date) == 9){
				if (strcmp(usr_type, read_type) == 0){
					total_subscribers = total_subscribers + 1;
					if (strcmp(read_claim,"0") == 0){
						exhausted_subscribers = exhausted_subscribers + 1;
					}
					
					
		}
	}
			fclose(user_data);
			printf("\nLifetime  Subscribers\n");
			printf("--------------------------\n");
			printf("Total Subscribers ==> %d\n",total_subscribers);
			printf("Subscribers who have exhausted their claim limit ==> %d\n\n\n",exhausted_subscribers);
			goto admin_startt;
			break;
		}
		case 6 :{
			system("cls");
			main();
			break;
		}
		default :{
			system("cls");
			printf("-----------------------------\n");
			printf("Please Type an Valid input\n");
			printf("-----------------------------\n\n");
			goto admin_startt;
			break;
		}
	}
	
	
}





























/*This function ask users last time if they really want to exit
 and exit from the program or goes back to main menu. */

void Exit(){
	int yes_no;
	system("cls");
	printf("Exit menu\n");
	printf("--------------------------------\n");
	printf("Do you sure want to exit\n");
	printf("1.Yes\n");
	printf("2.No\n");
	scanf("%d", &yes_no);
	if (yes_no == 1){
		printf("Exitting....\n");
		exit(0);
	}else if (yes_no == 2){
		system("cls");
		main();
	}else{
		printf("Please type an valid input...");
		sleep(5);
		system("cls");
		Exit();
	}
	

}

