#pragma once

#ifndef JAIME_CHAPINAL_H
#define JAIME_CHAPINAL_H

#include <string>
#include <vector>

struct Study
{
	std::string		_Degree;
	std::string		_University;
	std::string		_Date;

	Study (std::string strDegree, std::string strUniversity, std::string strYears) 
			:	_Degree(strDegree), _University(strUniversity), _Date(strYears)	{};
};

struct Job
{
	std::string		_Company;
	std::string		_Category;
	std::string		_Date;
	std::string		_Description;

	Job	(std::string strCompany, std::string strCategory, std::string strYears, std::string strDesc) 
			:	_Company(strCompany), _Category(strCategory), _Date(strYears), _Description(strDesc)	{};
};

struct Game
{
	std::string		_Name;
	std::string		_Year;
	std::string		_Technology;
	std::string		_Web;

	Game	(std::string strName, std::string strYear, std::string strTechnology, std::string strWeb) 
			:	_Name(strName), _Year(strYear), _Technology(strTechnology), _Web(strWeb)	{};
};

struct Publication
{
	std::string		_Title;
	std::string		_Congress;
	std::string		_Year;
	std::string		_URL;

	Publication	(std::string strTitle, std::string strCongress, std::string strYear, std::string strURL)
			:	_Title(strTitle), _Congress(strCongress), _Year(strYear), _URL(strURL)	{};
};

struct Skill
{
	std::string		_Name;
	int			iLevel;	//[0-3]
	
	Skill	(std::string strName, int level)
			:	_Name(strName), iLevel(level)	{};
};

class JaimeChapinal
{
public:
	void	SetStudies	()
		{
			m_vStudies.push_back(Study("Technical Engineer in Computer Management","Charles III University of Madrid", "2007-2010"));
			m_vStudies.push_back(Study("Computer Science Degree","Charles III University of Madrid", "2010-2011"));
			m_vStudies.push_back(Study("Master in Software Development","University of Granada","2011-2012"));
			m_vStudies.push_back(Study("Master in Video Games Development","Complutense University of Madrid","2012-2013"));
		}

	void	SetJobs		()
		{
			m_vJobs.push_back(Job("Mediapost Spain","Junior programmer", "2010-2011", ".NET programmer / C#"));
			m_vJobs.push_back(Job("Simfor","Programmer", "2012-Act.", "Simulators programmer / C++"));
		}

	void	SetGames	()
		{
			m_vGames.push_back(Game("SuperEnjutoIA*", "2011","XNA/C#","http://www.superenjutoia.es"));
			m_vGames.push_back(Game("TAF Kinect", "2012","Kinect/WPF/C#","http://www.tafkinect.com"));
			m_vGames.push_back(Game("BeatJamp", "2012","Unity3D/C#","http://globalgamejam.org/2013/beat-jamp"));
			m_vGames.push_back(Game("Golem Hunter", "2013","Unity3D/C#","http://golemhunterthegame.wix.com/index"));
			m_vGames.push_back(Game("Gloom", "2013","Ogre/C++","http://www.gloomgame.com"));
			m_vGames.push_back(Game("13Floors", "2014","Unity3D/C#","http://globalgamejam.org/2014/games/13floors"));
		}

	void	SetPublications	()
	{
		m_vPublications.push_back(Publication("Tecnicas de Interaccion Natural usando Kinect",
			"Procedings of the 13th International Conference on Interaccion Persona-Ordenador", "2012", 
			"http://dl.acm.org/citation.cfm?id=2379650&dl=ACM&coll=DL"));
	}

	void	SetSkills	()
	{
		m_vSkills.push_back(Skill("C++",3));
		m_vSkills.push_back(Skill("C#", 2));
		m_vSkills.push_back(Skill(".NET",2));
		m_vSkills.push_back(Skill("Java",1));
		m_vSkills.push_back(Skill("OpenSceneGraph/OpenGL",2));
		m_vSkills.push_back(Skill("DDBB: Oracle/mySQL/Access",2));
		m_vSkills.push_back(Skill("Visual Studio 2005/2008/2010",3));
		m_vSkills.push_back(Skill("Unity3D",2));
		m_vSkills.push_back(Skill("Eclipse",1));
		m_vSkills.push_back(Skill("SVN",2));
		m_vSkills.push_back(Skill("Windows",3));
		m_vSkills.push_back(Skill("Linux",2));
		m_vSkills.push_back(Skill("Android/iOS",1));
		m_vSkills.push_back(Skill("HTML5/CSS3",2));
		m_vSkills.push_back(Skill("Photoshop",2));
	}
	

public:	//Inline methods
	std::vector<Study>			GetStudies			()					{ return m_vStudies; }
	std::vector<Job>			GetJobs				()					{ return m_vJobs; }
	std::vector<Game>			GetGames			()					{ return m_vGames; }
	std::vector<Publication>		GetPublications			()					{ return m_vPublications; }
	std::vector<Skill>			GetSkills			()					{ return m_vSkills; }

	std::string				GetName				()					{ return m_Name; }
	std::string				GetBirthdate			()					{ return m_Birthdate; }
	std::string				GetCity				()					{ return m_City; }

	std::string				GetEmail			()					{ return m_Email; }
		void					SetEmail			(std::string strEmail)			{ m_Email = strEmail; }
	std::string				GetWeb				()					{ return m_Web; }
		void					SetWeb				(std::string strWeb)			{ m_Web = strWeb; }
	std::string				GetTelephone			()					{ return m_Telephone; }
		void					SetTelephone			(std::string strTelephone)		{ m_Telephone = strTelephone; }

	

public: //Const
		JaimeChapinal			() 	: m_Name("Jaime Chapinal Cervantes"), m_Birthdate("08/05/1989"), m_City("Madrid") {} ;
		~JaimeChapinal			()									{} ;

private: // Data
	std::string				m_Name;
	std::string				m_Birthdate;
	std::string				m_City;
	std::string				m_Email;
	std::string				m_Telephone;
	std::string				m_Web;

	std::vector<Study>			m_vStudies;
	std::vector<Job>			m_vJobs;
	std::vector<Game>			m_vGames;
	std::vector<Publication>		m_vPublications;
	std::vector<Skill>			m_vSkills;
};

#endif