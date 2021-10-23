 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# RPG Project: Down With The System
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Jeffrey Hata](https://github.com/Jeff591), [Cameron Fong](https://github.com/CameronSF), [Pedro Gonzalez](https://github.com/pgonz028), [Nathan Wong](https://github.com/nathanw1510)  
 
 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list, start thinking about the features you will implement, what design patterns can help you implement them, and why. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). Your project needs to implement at least two design patterns iteratively, which you will have to justify for later phases.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings. While Daily Scrums are not required we highly recommend you practice them too.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory or Visitor
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * Each member of the group must actively participate in the Github Project board and reviewing commited code.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold one check-in meeting with your lab TA in addition to the final demo.

## Project Description
 > * Why is it important or interesting to you?
 >   * We find this project interesting because many of us enjoy playing video games and we are interested in the game making process. Some of us have coded text-based games in the past and we want to further our game design and development knowledge.  
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * Language: C++; this is the language that our group is most comfortable with and has the most experience with. Since it is an object oriented programming language, it should help us create objects like enemies, players, items, etc. 
 >   * [Replit](replit.com) - an online IDE that allows programmers to collaborate simultaneously on the same project. This will help make collaboration more efficient if multiple users need to work on the same files. The downside to this program is that the stability of its connection to the server it is hosted on can be unreliable. 
 >   * [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/): a program that allows programmers to use git commands on their local machine. It also allows programmers to send and receive code from their local repositories, and from Github. 
 >   * [Github](github.com) internet cloud used to store, manage, track, and control changes to projects and their respective code. We are using github in order to store our code onto one location, as well as be able to use the kanban feature on github to track the progress of features in our game 
 >   * [Google Docs](docs.google.com): a text editor that allows live collaboration between multiple users. This program will help us brainstorm ideas, create design documents, and store other resources that might help us in the creation of our game. 
 > * What will be the input/output of your project? What are the features that the project provides?
 >   * Our game is a turned-based RPG game that starts off with the player character being trapped inside a computer due to a powerful computer virus. The goal of the game is to fight your way to the sources of the virus and take it down to free the computer and the player character. 
 >   * The user will input to select and control a premade character that is part of one of three selectable classes. Each class will have superior stats in one category, but have lower stats in another to make the choice meaningful. 
 >   * The user will be able to traverse around a small map that has different areas to visit like towns and dungeons. In towns you can buy items and sell items. In dungeons, the player will be able to fight enemies, gather loot, and progress the story. 
 >   * The user’s character will have an inventory system that can hold different items like potions, key items, etc. 
 >   * The main gameplay will take the form of turn-based battles similar to games like Undertale, Final Fantasy, Pokemon, etc. The user will have a menu of options to select during battle like attack, defend, items, and battle skills. 
 >   * The player character will have stats like health, attack points, defence points, speed points, accuracy points, etc. These stats can be changed through use of weapons, armor, item effects, etc. 
 >  
 > 
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for your project and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
