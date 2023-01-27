/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int extraNeed = 0;
        int totalPetrol = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            totalPetrol += p[i].petrol - p[i].distance;
            if (totalPetrol < 0)
            {
                extraNeed += totalPetrol;
                totalPetrol = 0;
                start = i + 1;
            }
        }
        if (extraNeed + totalPetrol >= 0)
            return start;
    
        return -1;
    }
};
