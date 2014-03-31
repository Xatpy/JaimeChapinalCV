// JaimeChapinalCV_program.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h> 
#include <string>

#include "JaimeChapinalCV.h"

int ReadInput()
{	
	std::cout << "Option: ";
	std::string input;
	getline (std::cin, input);
	if ( (input == "0") || (input == "1") || (input == "2") || (input == "3")
						|| (input == "4") || (input == "5") || (input == "6") )
		return atoi(input.c_str());	
	return -1;
}

void ShowContinue()
{
	std::cout << std::endl;
	std::cout << "Press any key to continue...";
	getch();
	std::cout << std::endl;
	std::cout << std::endl;
}

void ShowPersonalData(JaimeChapinal me)
{
	std::cout << std::endl;
	std::cout << "#####::: Personal data :::##### " << std::endl;
	std::cout << std::endl;
	std::cout << "- Name: " << me.GetName() << std::endl;
	std::cout << "- Birthdate: " << me.GetBirthdate() << std::endl;
	std::cout << "- Telephone number: " << me.GetTelephone() << std::endl;
	std::cout << "- E-mail: " << me.GetEmail() << std::endl;
	std::cout << "- Web: " << me.GetWeb() << std::endl;
	ShowContinue();
}

void ShowStudiesData(std::vector<Study> vecStudies)
{
	std::cout << std::endl;
	std::cout << "#####::: Studies info :::##### " << std::endl;
	std::cout << std::endl;
	std::cout << "||| Degre  -  University  -  Years |||" << std::endl;
	std::cout << std::endl;

	std::vector<Study>::reverse_iterator	iter;
	for (iter = vecStudies.rbegin(); iter != vecStudies.rend(); ++iter)
	{
		std::cout <<"+ " << iter->_Degree << " - " << iter->_University << " - " << iter->_Date << std::endl;
	}
	ShowContinue();
}

void ShowPublications(std::vector<Publication> vecPublications)
{
	std::cout << std::endl;
	std::cout << "#####::: Publications :::##### " << std::endl;
	std::cout << std::endl;
	std::cout << "||| Title - Congress - Year - URL " << std::endl;
	std::cout << std::endl;

	Publication pub = vecPublications[0];
	std::cout << "~ " << pub._Title << " - " << pub._Congress << " - " << pub._Year << " - " << pub._URL << std::endl;
	ShowContinue();
}

void ShowProfessionalData(std::vector<Job> vecJobs)
{
	std::cout << std::endl;
	std::cout << "#####::: Professional experience :::##### " << std::endl;
	std::cout << std::endl;
	std::cout << "||| Company - Category - Years - Description |||" << std::endl;
	std::cout << std::endl;

	std::vector<Job>::reverse_iterator  iter;
	for (iter = vecJobs.rbegin(); iter != vecJobs.rend(); ++iter)
	{
		std::cout << "+ " << iter->_Company << " - " << iter->_Category << " - " <<  iter->_Date;
		std::cout << " - " << iter->_Description << std::endl;
	}
	ShowContinue();
}

void ShowGames(std::vector<Game> vecGames)
{
	std::cout << std::endl;
	std::cout << "#####::: Games developed :::##### " << std::endl;
	std::cout << std::endl;
	std::cout << "||| Game - Year - Technology - Web |||" << std::endl;
	std::cout << std::endl;

	std::vector<Game>::reverse_iterator  iter;
	for (iter = vecGames.rbegin(); iter != vecGames.rend(); ++iter)
	{
		std::cout <<"+ " << iter->_Name << " - " << iter->_Year << " - " << iter->_Technology << " - " << iter->_Web << std::endl;
	}

	ShowContinue();
}

void ShowSkills(std::vector<Skill> vecSkill)
{
	std::cout << std::endl;
	std::cout << "#####::: Skills :::##### " << std::endl;
	std::cout << std::endl;
	std::cout << "||| Skill  :  Level (about 3) |||" << std::endl;
	std::cout << std::endl;

	std::vector<Skill>::iterator	iter;
	for (iter = vecSkill.begin(); iter != vecSkill.end(); ++iter)
	{
		std::cout <<"~ " << iter->_Name << " : ";
		for (int level = 0; level < iter->iLevel; ++level)
		{
			std::cout << "*";
		}
		std::cout << std::endl;		
	}
	ShowContinue();
}

void ShowMainMenu()
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "------------ MAIN MENU ------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "1) Personal data" << std::endl;
	std::cout << "2) Studies info" << std::endl;
	std::cout << "3) Publications" << std::endl;
	std::cout << "4) Professional experience" << std::endl;
	std::cout << "5) Indie games" << std::endl;
	std::cout << "6) Skills" << std::endl;
	std::cout << "0) Exit" << std::endl;
	std::cout << std::endl;
}

void ShowTitle(JaimeChapinal me)
{
	std::cout << "***********************************" << std::endl;
	std::cout << "*** CV " << me.GetName() << " ***" << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	JaimeChapinal me;

	me.SetEmail("jaime.chapinal@gmail.com");
	me.SetWeb("www.jaimechapinal.com");
	me.SetTelephone("678-97-57-76");

	me.SetStudies();
	me.SetPublications();
	me.SetJobs();
	me.SetGames();
	me.SetSkills();

	ShowTitle(me);

	bool bExit = false;
	int iOption = -1;
	while (!bExit)
	{
		ShowMainMenu();	
		iOption = ReadInput();
		switch (iOption)
		{
			case 1:	//Personal data
				ShowPersonalData(me);
			break;
			case 2:	//Studies data
				ShowStudiesData(me.GetStudies());
			break;
			case 3: //Professional data
				ShowPublications(me.GetPublications());
			break;
			case 4: //Professional data
				ShowProfessionalData(me.GetJobs());
			break;
			case 5:	//Games
				ShowGames(me.GetGames());
			break;
			case 6:	//Skills
				ShowSkills(me.GetSkills());
			break;
			case 0: //Exit
				bExit = true;
			break;
			default:
				std::cout << "Invalid option. Please, try again. " << std::endl;
				std::cout << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "Thanks for your time! =) " << std::endl;
	getch();
	return 0;
}

