import random
secretCommand="xxxuuu"

class Treasure:
# Treasure format:
#   Name,
#   Description
#   Number of Points per treasure
#   Treasures: Lamp, Stone, Necklace, Mirror, and Jewels
    def __init__(self, name, description, points):
        self.name = name
        self.description = description
        self.points = points

    def getName(self):
        return self.name
    def setName(self,newName):
        self.name = newName
    
    def getDescription(self):
        return self.description

    def setDescription(self,newDescription):
        self.description=newDescription


    def getPoints(self):
        return self.points;
    def setPoints(self,newPoint):
        self.points = newPoint

class Room:
# Room format:
#   Name,
#   Description, 
#   Room dictionary, 
#   Treasure Objects in Room Placed
    def __init__(self,name,description,reachableRoom,treasureList):
        self.name=name;
        self.description=description
        self.reachableRoom=reachableRoom
        self.treasureList=treasureList

    def getName(self):
        return self.name
    def setName(self,newName):
        self.name=newName
    def getDescription(self):
        return self.description
    def setDescription(self,newDescription):
        self.description=newDescription
    def getReachableRoom(self):
        return self.reachableRoom
    def setReachableRoom(self,newReachableRoom):
        self.reachableRoom=newReachableRoom

    def getTreasureList(self):
        return self.treasureList
    def setTreasureList(self,newTreasureList):
        self.treasureList=newTreasureList

class Player:
# Player format:
#   Current Room,
#   Number of Lives
#   Accumulated list of treasure
#   Treasures: Lamp, Stone, Necklace, Mirror, and Jewels
#   Method to return number of points for the treasure collected

    def __init__(self, currentRoom,numberOfLives,listOfTreasure):
        self.currentRoom=currentRoom
        self.numberOfLives=numberOfLives
        self.listOfTreasure=listOfTreasure

    def getCurrentRoom(self):
        return self.currentRoom
    def setCurrentRoom(self,newCurrentRoom):
        self.currentRoom=newCurrentRoom
    def getNumberOfLives(self):
        return self.numberOfLives
    def setNumberOfLives(self,newNumberOfLives):
        self.numberOfLives=newNumberOfLives
    def getListOfTreasures(self):
        return self.listOfTreasure
    def setListOfTreasures(self,newListOfTreasures):
        self.listOfTreasure=newListOfTreasures
    def getPoints(self):
        lst = self.getListOfTreasures()
        points =0
        if(len(lst)>0):
            for x in lst:
                points = points + x.getPoints()
        return points
    def secretLife(self,command):
        if command is secretCommand:
            self.numberOfLives = self.numberOfLives+1
        
     

class Game:
# Game format:
#   Player and Room for exit/play method,
#   init method for the game it will create player, rooms, set starting room for player, and set exit room.
#   Set up the treasure in the rooms  
    treasure=[]
    room = []
    def __init__(self):
     
    
        dungeon = Room("dungeon","just a dungeon",{"n":"treasury","s":"hall"},[])
        treasury = Room("treasury","just a treasury",{"s":"dungeon"},[])
        hall = Room("hall","just a hall",{"s":"armory","n":"dungeon","e":"kitchen","w":"cellar"},[])
        cellar = Room("cellar","just a cellar",{"e":"hall","w":"game room"},[])
        gameRoom =Room("game room","just a game room",{"e":"cellar"},[])
        kitchen = Room("kitchen","just a kitchen",{"e":"balcony","w":"hall"},[])
        balcony = Room("balcony","just a balcony",{"w":"kitchen"},[])
        armory = Room("armory","just an armory",{"n":"hall","s":"basement"},[])
        basement = Room("basement","just a basement",{"n":"armory"},[])      
        self.room=[dungeon,treasury,hall,cellar,gameRoom,kitchen,balcony,armory,basement]
        self.treasure.append(Treasure("lamp","gets you through dark",20))
        self.treasure.append(Treasure("stone","can be used to hit",30))
        self.treasure.append(Treasure("Necklace","a gift",30))
        self.treasure.append(Treasure("mirror","a magical mirror",30))
        self.treasure.append(Treasure("Jewels","enhances your beauty",30))
        self.treasure.append(Treasure("ring","a magical ring",30))
        self.treasure.append(Treasure("shirt","new shirt to wear",20))
        #distributing treasure randomly

        self.randomFiller()

        #initializing player and setting exit room
        self.player = Player(dungeon,3,dungeon.getTreasureList())
        self.exitRoom =balcony

    def randomFiller(self):
         
           
            for i in range(0,9):
                tlist =[]
                rand = random.randint(0,6 )
                tlist.append(self.treasure[rand])
                for j in range(0,5):
                    rand2 = random.randint(0,20)
                    if rand2<7:
                         tlist.append(self.treasure[rand2])
                self.room[i].setTreasureList(tlist)           






    def getExitRoom(self):
        return self.exitRoom
    def setExitRoom(self,newExitRoom):
        self.exitRoom=newExitRoom
    def play(self):
        while 1==1:
            currRoom = self.player.getCurrentRoom()
            print("Hi currently you are in "+str(currRoom.getName()))
            print("the room has a list of following items in your treasure")
           
            roomTreasure=currRoom.getTreasureList()
           
            lst = self.player.getListOfTreasures()
            print len(roomTreasure)
            
            for x in range(0,len(roomTreasure)):

                print roomTreasure[x].getName() +" ",
                lst.append(roomTreasure[x])
            print("")
            currRoom.setTreasureList([]) ##no treasure left in the room to pick
            points =self.player.getPoints()
                    
            print("your total point currently is "+str(points))
            direction = raw_input("Enter the direction you want to go(n,s,w,e)")
            
            roomDirection = currRoom.getReachableRoom() 
            temp = roomDirection.get(direction)
            if temp is not None:

                rooms = roomDirection[direction]

                if direction in roomDirection:
                    for i in range(0,len(self.room)):
                        if self.room[i].getName() is rooms:
                            self.player.setCurrentRoom(self.room[i])
                            break

            else:
                self.player.setNumberOfLives(self.player.getNumberOfLives()-1)
                print("oops you lost one life!!!")

            currLife = self.player.getNumberOfLives()
            if currLife == 0:
                print("Game over all your life ended")
                break
            if currRoom.getName() is self.exitRoom.getName():
                if self.player.getPoints()>100:
                    print("Game won nice job you found the exit")
                else:
                    print("You didnt won,you couldnt reach exit with atleast 100 points come back later")
                  

g = Game()
g.play()
