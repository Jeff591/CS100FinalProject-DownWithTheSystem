 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# RPG Project: Down With The System
 
Authors: [Jeffrey Hata](https://github.com/Jeff591), [Cameron Fong](https://github.com/CameronSF), [Pedro Gonzalez](https://github.com/pgonz028), [Nathan Wong](https://github.com/nathanw1510)  
 
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
 >   * Language: C++: this is the language that our group is most comfortable with and has the most experience with. Since it is an object oriented programming language, it should help us create objects like enemies, players, items, etc. 
 >   * [Replit](replit.com): an online IDE that allows programmers to collaborate simultaneously on the same project. This will help make collaboration more efficient if multiple users need to work on the same files. The downside to this program is that the stability of its connection to the server it is hosted on can be unreliable. 
 >   * [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/): a program that allows programmers to use git commands on their local machine. It also allows programmers to send and receive code from their local repositories, and from Github. 
 >   * [Github](github.com): internet cloud used to store, manage, track, and control changes to our project and their respective code. We are using github in order to store our code onto one location, as well as be able to use the kanban feature on github to track the progress of features in our game
 >   * [Google Docs](docs.google.com): a text editor that allows live collaboration between multiple users. This program will help us brainstorm ideas, create design documents, and store other resources that might help us in the creation of our game. 
 > * What will be the input/output of your project? What are the features that the project provides?
 >   * Our game is a turned-based RPG that starts off with the player character being trapped inside a computer due to a powerful computer virus. The goal of the game is to fight your way to the sources of the virus and take it down to free the computer and the player character.
 >   * The user will input to select and control a premade character that is part of one of three selectable classes: Defender, Firewall, and Cleaner. Each class will have superior stats in one category, but have lower stats in another to make the choice meaningful.
 >   * The user will be able to visit towns and dungeons. In towns you can buy items and sell items. In dungeons, the player will be able to fight enemies, gather loot, and progress the story.
 >   * Between battles in dungeons, the player will have the opportunity to do a variety of actions like checking their character’s stats, checking the current items in their inventory, equipping new armors and weapons, buying or selling at the town, or continuing on to the next battle. 
 >   * The user’s character will have an inventory system that can hold different items like potions, weapons, and armor.
 >   * The main gameplay will take the form of turn-based battles similar to games like Undertale, Final Fantasy, Pokemon, etc. The user will have a menu of options to select during battle like attack, items, and battle skills.
 >   * The player character will have stats like health, attack points, defense points, and speed points. These stats can be changed through use of different armors and weapons.

 >  
 > 
## Class Diagram
 > ![Phase II_ UML Diagram](https://user-images.githubusercontent.com/66803305/144090267-2b10d5f9-b88a-4af5-b782-b099268d099e.png)
 > [UML Diagram](https://lucid.app/publicSegments/view/65744f78-3fde-48ce-ae6d-6c075e1613d7/image.jpeg)
 > * Game class: The game client runs the main function of our program runGame(). It also contains functions like battle(), intermission(), and create_character() that will act as the core features of the game. The game class also includes private members for the 5 dungeons, player character, the town, and a bool variable gameOver to signify when the game is ended. 
 > * Player class: The player class includes several private members including a vector of vector of items to represent the inventory with a composition connection to the items class, a composition connection to skillset to represent a unique skill each type of character will have, int money to represent money the player has, and currentWeapon and currentArmor pointers to represent which weapon/armor respectively the player current has. The player class also has several public member functions which include attack() which is calculates how much damage the opponent takes based on the player’s power + current weapon - enemy defense, set_current_armor() and set_current_weapon() which selects what weapon currentWeapon and what armor currentArmor will store, and check_stats() to see the player’s health, power, defense, and speed. Some other functions include display_inventory() which shows the user the current inventory, add_item() which is used when the player buys an item, remove_item() when the player sells an item, and other getter functions to get access to protected members. The Player class acts as the parent class of the different player character classes that the user will choose to play as. These classes include Defender, Cleaner, and Firewall which all come with their own unique stats and skills. 
 > * SkillSet class: This class is a composition of the player class and serves to set the skill the player has after choosing their respective class and becomes the parent function for child classes: Shieldbash is set to the player’s skill if they choose the Defender class, CleanSweep if they choose Cleaner class, and rebuild if they choose FireWall class. Comboskill also inherits from SkillSet to combine two skills together. 
 > * Character class: The class all entities (enemies and the player) inherit from. These derived classes will all include protected members as integer values for health, power, defense, and speed so that all public functions of the player and enemy class can have access to them. The character class also includes a virtual void for attack in which enemies take damage depending on the combination of attack on the player and the player’s weapon while players take damage depending on the enemy’s attack subtracted by the player’s defense. The character class also includes a protected member for the name of the character as well as getters for all of these protected members.
 > * Enemy class: This inherits from the character class and all enemies will have varying health points, power/attack stat, speed, and defense. In addition, it also includes a virtual attack function as the amount of damage they inflict on the player is calculated differently from the the player’s damage on enemies (see character class for more information), and also include void set_health in order to set the health of enemies after being attacked by the player and is dependent on the player’s main stats as well as their current weapon.
 > * Dungeon class: This is a composition of the enemy class that will store a vector of the enemy class (each dungeon containing 3 enemies) to represent the encounters for each dungeon for the game. The dungeon class also includes int get_reward() to reward the player with a certain amount of money after a particular dungeon and all its respective enemies are defeated.
 > * Town class: This like the dungeon class are two destinations the player can travel to and includes connections to the player class as it will modify the vector of vector items that the player has to add or take away items from the player (buy and sell functions respectively), as well as modify the integer money the player has through increasing money if selling an item or subtracting money if buying an item. The town class also includes buy and sell confirmation to make sure the player really wants to be selling or buying a particular item.
 > * Item class: this is also a composition of the player class which is used in the vector of vector item private members of the player class representing their inventory. This class also serves as the parent class of the potion, armor, and weapon class, allowing the protected member sell_price to indicate the amount of money given to the player when a particular item is sold at the town, string itemType to indicate what type of item (armor, weapon, or potion) something is, string name for the item’s name, and string description for information about a particular item. The item class also includes the public virtual void function check_stats() for the player to see the particular stats (Ex: attack power of a weapon) between dungeons.
 > * Potion class: This class inherits from the item class which will become the parent class for all subsequent potion types (as of now only healing potion exists) and includes all protected members of the item class as well as int alter to determine how much of a particular stat string type to modify. Check_stats is also apparent in the potion class which allows the player to see what a particular potion can do.
 > * Weapon class: The weapon class will inherit from the item class and be the parent function for each weapon in the game. In addition, the class includes its own private member attack to specify how much attack each weapon can inflict, as well as a check_stats public function to see said stats.
 > * Armor class:  The armor class inherits from the item class with each armor having its respective sell value, name, itemType, and description from the item class, as well as its respective int protected member to keep track of the amount of defense each armor has which is shown to the player through the check_stats public function. This class is the parent function for all the armors in the game with their own classes that inherit from the general armor class.

> 
 
 > ## Phase III
 > ![Phase II_ UML Diagram](https://user-images.githubusercontent.com/66803305/144090267-2b10d5f9-b88a-4af5-b782-b099268d099e.png)
 > [UML Diagram](https://lucid.app/publicSegments/view/65744f78-3fde-48ce-ae6d-6c075e1613d7/image.jpeg)
 > * Strategy Pattern for the SkillSet Classes
 >   * We chose to use the strategy pattern to help implement the SkillSet classes because we wanted the player to be able to select their battle skills depending on the character they chose. The SkillSet class acts as the abstract strategy and gives the interface to its derived classes which each act as concrete strategies. This design pattern helped us write better code by allowing us to better organize the skills we want to implement and expand the number of skills if we want to in the future. It also made it easier for certain character classes to have their own unique battle options.
 > * Composite Pattern for the ComboSkill Class
 >   * We chose to use the composite pattern along with the strategy pattern to implement the ComboSkill Class so that the player has the ability to use an alternative battle option than just the one skill associated with their character. The ComboSkill class acts as the composite as it is a composition of the SkillSet Class. This allows the ComboSkill class to hold two different SkillSet objects within itself so that the ComboSkill object can have the effect of two different skills at once. The use of the composite pattern made it much easier to implement this mechanic into our game by allowing us to treat the ComboSkill class the same as the other SkillSet classes in other functions like battle(), while also cutting down on repetitive code when trying to put two skills together. 

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 >
 > ![Character_Creation](https://user-images.githubusercontent.com/67081225/143794771-c8637156-2b8e-44eb-813b-1d7c942d1479.PNG)
 > 
 > * Creation of the main character
 > 
 > ![Battle](https://user-images.githubusercontent.com/67081225/143794808-735784a6-4f89-4788-96eb-4e5e918d752d.PNG)
 > 
 > * Main battle screen
 > 
 > ![Skill_Select](https://user-images.githubusercontent.com/67081225/143794836-434902d7-def7-46b6-a2b9-36e4fa650c70.PNG)
 > 
 > * Selecting a skill during battle
 >
 >![Buy](https://user-images.githubusercontent.com/67081225/143794940-cbffc131-e592-473f-a2dc-897d9fe15644.PNG)
 >
 > * Main buying screen
 > 
 > ![Sell](https://user-images.githubusercontent.com/67081225/143794969-2a3679e7-b145-4219-8c44-ff8ce4183c53.PNG)
 > * Main selling screen
 > 
 > ![Inventory](https://user-images.githubusercontent.com/67081225/143795007-819c2e18-e217-4bc9-9821-ab131db7635a.PNG)
 > 
 > * Inventory screen 
 > 
 > ![Check Stats](https://user-images.githubusercontent.com/67081225/143795041-8f7a4387-05ad-4061-ae19-d866bc4be014.PNG)
 > 
 > * Checking player stats screen
 > 
 > ![Death and Valgrind](https://user-images.githubusercontent.com/67081225/143795232-5a917173-579b-4279-ac64-49d6cac42af8.PNG)
 > * The game over screen along with a valgrind report showing memcheck clean


 ## Installation/Usage
 > *Note: do not put "" into command-line input*
 > 1. To install the game, copy the repository on to a linux console by using "git clone --recursive https://github.com/cs100/final-project-jhata004-cfong027-pgonz028-nwong063.git"
 > 2. Once the directory is downloaded, run the commands "cmake3 ." and "make" to create the main executable.
 > 3. Once the executable is made, put in "./main" into the command-line and enjoy!
 ## Testing
 > * We created unit tests using googletest to check our functions after we finished portions of the game like the battle features and shopping features, or when we finsihed creating classes. The functions we decided to include in our testing were mostly getter functions as well as setter functions because they provided the backbone of most of our features. 
 > * Functions that mainly served to output text to the console or took in user input were not tested through googletest but instead tested manually through playing the game several times to make sure the inputs were read correctly and the ouput was what we expected.
 > * Through our playtesting, we also looked for memory leaks within our program by testing every possible action that the user could put into our program. We were able to find many errors in our code this way and were able to come up with more efficient methods of coding some algorithms. 
 > 
 > ![unit_test](https://user-images.githubusercontent.com/66803305/143986836-9f8d393e-90b8-486d-80b5-ef80e6b8e221.PNG)
 > * 57 unit tests total
 
