/*
ID: og192li1
ROG: castle
PROB: castle
LANG: C
 */
#include<stdio.h>
#include<stdlib.h>

char const Visited = 2;
char const NotVisited = 0;
char const Exist = 1;
char const NotExist = 0;

typedef struct Wall
{
        char East;
        char Sourth;
        char West;
        char North;
}Wall;

typedef struct Room
{
        char x;
        char y;
        Wall walls;
        char RoomNumber;
        int *RoomSize;
        char IsVisited;
}Room;

Room rooms[51][51];
int NumberOfRoom = 0;
int LargestSize = 0;

void InitializeRooms(int colume, int cow)
{
        int i, j;
        for(i = 0; i < cow; i++)
        {
                for(j = 0; j < colume; j++)
                {
                        rooms[i][j].x = i;
                        rooms[i][j].y = j;
                        rooms[i][j].RoomSize = 0;
                        rooms[i][j].IsVisited = NotVisited;
                        rooms[i][j].walls.East =
                        rooms[i][j].walls.Sourth =
                        rooms[i][j].walls.West =
                        rooms[i][j].walls.North = NotExist;
                        unsigned int WallNumber = 0;
                        scanf("%ud", &WallNumber);
                        rooms[i][j].walls.West = (0x0001 & WallNumber) ? Exist : NotExist;
                        rooms[i][j].walls.North = (0x0002 & WallNumber) ? Exist : NotExist;
                        rooms[i][j].walls.East = (0x0004 & WallNumber) ? Exist : NotExist;
                        rooms[i][j].walls.Sourth = (0x0008 & WallNumber) ? Exist : NotExist;
                }
        }
}

void GoThroughRoom(int x, int y, int NumberOfRoom, int *RoomSize)
{
    rooms[x][y].IsVisited = Visited;
    rooms[x][y].RoomNumber = NumberOfRoom;
    rooms[x][y].RoomSize = RoomSize;
    (*(rooms[x][y].RoomSize)) ++;
    if(rooms[x][y].walls.East == NotExist)
    {
        if(rooms[x][y + 1].IsVisited == NotVisited)
        {
            GoThroughRoom(x, y + 1, NumberOfRoom, RoomSize);
        }
    }
    if(rooms[x][y].walls.North == NotExist)
    {
        if(rooms[x - 1][y].IsVisited == NotVisited)
        {
            GoThroughRoom(x - 1, y, NumberOfRoom, RoomSize);
        }
    }
    if(rooms[x][y].walls.Sourth == NotExist)
    {
        if(rooms[x + 1][y].IsVisited == NotVisited)
        {
            GoThroughRoom(x + 1, y, NumberOfRoom, RoomSize);
        }
    }
    if(rooms[x][y].walls.West == NotExist)
    {
        if(rooms[x][y - 1].IsVisited == NotVisited)
        {
            GoThroughRoom(x, y - 1, NumberOfRoom, RoomSize);
        }
    }
}

void FinsLargest(int colume, int cow)
{
    int i, j;
    for(i = 0; i < cow; i++)
    {
        for(j = 0; j < colume; j++)
        {
            if(rooms[i][j].IsVisited == NotVisited)
            {
                NumberOfRoom ++;
                int *RoomSize = malloc(sizeof(int));
                (*RoomSize) = 0;
                rooms[i][j].RoomSize = RoomSize;
                GoThroughRoom(i, j, NumberOfRoom, RoomSize);
                if(LargestSize < *(rooms[i][j].RoomSize))
                {
                    LargestSize = *(rooms[i][j].RoomSize);
                }
            }
        }
    }
}

void RemoveOptimalWall(int colume, int cow)
{
    int i, j;
    int x = 0, y = 0;
    char directory ;
    int largestConnectedRoomSize = 0;

    for(i = 0; i < cow; i++)
    {
        for(j = 0; j < colume; j++)
        {
            if(rooms[i][j].walls.East == Exist)
            {
                if(j + 1 < colume)
                {
                    if(rooms[i][j + 1].RoomNumber != rooms[i][j].RoomNumber)
                    {
                        if(largestConnectedRoomSize < *(rooms[i][j + 1].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            largestConnectedRoomSize = *(rooms[i][j + 1].RoomSize) + *(rooms[i][j].RoomSize);
                            x = i;
                            y = j;
                            directory = 'E';
                        }
                        else if(largestConnectedRoomSize == *(rooms[i][j + 1].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            if(y > j)
                            {
                                x = i;
                                y = j;
                                directory = 'E';
                            }
                            else if(y == j && x < i)
                            {
                                x = i;
                                y = j;
                                directory = 'E';
                            }
                        }
                    }
                }
            }
            if(rooms[i][j].walls.West == Exist)
            {
                if(j - 1 >= 0)
                {
                    if(rooms[i][j - 1].RoomNumber != rooms[i][j].RoomNumber)
                    {
                        if(largestConnectedRoomSize < *(rooms[i][j - 1].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            largestConnectedRoomSize = *(rooms[i][j - 1].RoomSize) + *(rooms[i][j].RoomSize);
                            x = i;
                            y = j - 1;
                            directory = 'E';
                        }
                        else if(largestConnectedRoomSize == *(rooms[i][j - 1].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            if(y > j - 1)
                            {
                                x = i;
                                y = j - 1;
                                directory = 'E';
                            }
                            else if(y == j - 1 && x < i)
                            {
                                x = i;
                                y = j - 1;
                                directory = 'E';
                            }
                        }
                    }
                }
            }
            if(rooms[i][j].walls.Sourth == Exist)
            {
                if(i + 1 < cow)
                {
                    if(rooms[i + 1][j].RoomNumber != rooms[i][j].RoomNumber)
                    {
                        if(largestConnectedRoomSize < *(rooms[i + 1][j].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            largestConnectedRoomSize = *(rooms[i + 1][j].RoomSize) + *(rooms[i][j].RoomSize);
                            x = i + 1;
                            y = j;
                            directory = 'N';
                        }
                        else if(largestConnectedRoomSize == *(rooms[i + 1][j].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            if(y > j)
                            {
                                x = i + 1;
                                y = j;
                                directory = 'N';
                            }
                            else if(y == j && x < i + 1)
                            {
                                x = i + 1;
                                y = j;
                                directory = 'N';
                            }
                            else if(x == i + 1 && y == j && directory == 'E')
                            {
                                directory = 'N';
                            }
                        }
                    }
                }
            }
            if(rooms[i][j].walls.North == Exist)
            {
                if(i - 1 >= 0)
                {
                    if(rooms[i - 1][j].RoomNumber != rooms[i][j].RoomNumber)
                    {
                        if(largestConnectedRoomSize < *(rooms[i - 1][j].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            largestConnectedRoomSize = *(rooms[i - 1][j].RoomSize) + *(rooms[i][j].RoomSize);
                            x = i;
                            y = j;
                            directory = 'N';
                        }
                        else if(largestConnectedRoomSize == *(rooms[i - 1][j].RoomSize) + *(rooms[i][j].RoomSize))
                        {
                            if(y > j)
                            {
                                x = i;
                                y = j;
                                directory = 'N';
                            }
                            else if(y == j && x < i)
                            {
                                x = i;
                                y = j;
                                directory = 'N';
                            }
                            else if(x == i && y == j && directory == 'E')
                            {
                                directory = 'N';
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", largestConnectedRoomSize);
    printf("%d %d %c\n", x + 1, y + 1, directory);
}

int main(void)
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);

    int cow, colume;
    scanf("%d %d", &colume, &cow);
    InitializeRooms(colume, cow);
    FinsLargest(colume, cow);
    printf("%d\n", NumberOfRoom);
    printf("%d\n", LargestSize);
    RemoveOptimalWall(colume, cow);

    return 0;
}

