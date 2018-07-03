#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


//int CNOT = 1;
//int TOF = 5;
//int gateCount = 0;
//int cost = 0;

int main()
{
    int numFiles = 36;
    int num = 0;
    int i1[8], i2[8], i3[8];
    ifstream in;
    in.open("input.txt");
    in >> i1[num] >> i2[num] >> i3[num];
    num++;
    while(!in.eof())
    {
        in >> i1[num] >> i2[num] >> i3[num];
        num++;
    }
//    for(int i = 0; i < num; i++)
//   {
//       cout << i1[i] << " " << i2[i] << " " << i3[i] << endl;
//    }

    int a[8], b[8], c[8];
    for(int f = 0; f < numFiles; f++)
    {
    int CNOT = 1;
    int TOF = 5;
    int gateCount = 0;
    int cost = 0;

    ostringstream fileName;
    fileName << "crf3x3OneTwo_" << f << ".txt";
    ifstream fin;
    fin.open(fileName.str().c_str());

    num = 0;
    fin >> a[num] >> b[num] >> c[num];

    while(!fin.eof())
    {
        num++;
        fin >> a[num] >> b[num] >> c[num];
    }

    //cout << "num " << num << endl;
    cout << "Conservative Function " << f << endl;
    for(int i = 0; i < num; i++)
        cout << a[i] << " " << b[i] << " " << c[i] << endl;

    for(int i = 1; i <=6; i++)
    {
         for(int k = 2; k <=6; k++)
            if((a[k] == i1[k]) && (b[k] == i2[k]) && (c[k] == i3[k])) //testing to see if no transformation is required
                break;
    switch(i)
    {
        case 1:
        if(a[i]) //100 is in the pos of 001
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: a target: c" << endl;
            for(int i = 0; i <num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(c[j])
                {
                a[j] = !a[j];
                }
            }
            cout << "CNOT control: c target: a" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + (2 * CNOT);
            gateCount = gateCount + 2;
        }

        if(b[i]) //010 is in 001
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(b[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: b target: c" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(c[j])
                {
                b[j] = !b[j];
                }
            }
            cout << "CNOT control: c target: b" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + (2 * CNOT);
            gateCount = gateCount + 2;
        }
        break;

        case 2: //010 is not in pos. 100 is in 010's pos
        if((a[i] == 1) && (b[i] == 0) && (c[i] == 0))
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                b[j] = !b[j];
                }
            }
            cout << "CNOT control: a target: b" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(b[j])
                {
                a[j] = !a[j];
                }
            }
            cout << "CNOT control: b target: a" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + (2 * CNOT);
            gateCount = gateCount + 2;
        }

        else if((a[i] == 0) && (b[i] == 1) && (c[i] == 1))
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(b[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: b target: c" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + CNOT;
            gateCount = gateCount + 1;
        }

        else if((a[i] == 1) && (b[i] == 0) && (c[i] == 1))
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: a target: c" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                b[j] = !b[j];
                }
            }
            cout << "CNOT control: a target: b" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(b[j])
                {
                a[j] = !a[j];
                }
            }
            cout << "CNOT control: b target: a" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + (3 * CNOT);
            gateCount = gateCount + 3;
        }

        else if((a[i] == 1) && (b[i] == 1) && (c[i] == 0))
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(b[j])
                {
                a[j] = !a[j];
                }
            }
            cout << "CNOT control: b target: a" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + CNOT;
            gateCount = gateCount + 1;
        }
        else
            {
                break;
            }
        break;

        case 3:
        if((a[i] == 1) && (b[i] == 0) && (c[i] == 0))
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: a target: c" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                b[j] = !b[j];
                }
            }
            cout << "CNOT control: a target: b" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(b[j] && c[j])
                {
                a[j] = !a[j];
                }
            }
            cout << "Toffoli. control: b and c. target: a" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost + (2 * CNOT);
            cost = cost + TOF;
            gateCount = gateCount + 3;
        }


        else if(a[i] && b[i] && (c[i] == 0)) //when 110 is in the pos of 011. apply positive FRED with control in on middle (b)
        {
            for(int j = i; j <=7; j++)
            {
                if(a[j])
            {
                c[j] = !c[j];
            }
            }

            cout << "CNOT control: a target: c" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <=7; j++)
            {
                if(b[j] == 1 && c[j] == 1)
            {
                a[j] = !a[j];
            }
            }
            cost = cost + CNOT;
            cost = cost + TOF;
            gateCount = gateCount + 2;
            cout << "Toffoli. Control: b and c. Target: a" << endl;
            for(int i = 0; i < num; i++)
                {
                    cout << a[i] << " " << b[i] << " " << c[i] << endl;
                }
        }
        else if(a[i] && c[i] && (b[i] == 0)) //when 101 is in the pos of 011. apply positive FRED with control in on bottom line (c)
        {
            //cout << "case 3 2nd if: " << endl;
            //if(c[i])
            //{
           for(int j = i; j <=7; j++)
            {
                if(a[j])
            {
                b[j] = !b[j];
            }
            }

            cout << "CNOT control: a target: b" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <=7; j++)
            {
                if(b[j] == 1 && c[j] == 1)
            {
                a[j] = !a[j];
            }
            }
            cout << "Toffoli. Control: b and c. Target: a" << endl;
            cost = cost + CNOT;
            cost = cost + TOF;
            gateCount = gateCount + 2;

            for(int i = 0; i < num; i++)
                {
                    cout << a[i] << " " << b[i] << " " << c[i] << endl;
                }
            //}
        }

        else if(a[i] && b[i] && c[i]) //when 111 is in the pos of 011.
        {
            //cout << "case 3 2nd if: " << endl;
            //if(c[i])
            //{
           for(int j = i; j <=7; j++)
            {
                if(b[j] && c[j])
            {
                a[j] = !a[j];
            }
            }

            cout << "Toffoli control: b and c target: a" << endl;
            cost = cost + TOF;
            gateCount = gateCount + 1;

            for(int i = 0; i < num; i++)
                {
                    cout << a[i] << " " << b[i] << " " << c[i] << endl;
                }
        }

        else
        {
            break;
        }

        break;

        case 4: // this condition will never occur
        if((a[i] == 1) && (b[i] == 0) && (c[i] == 1))
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: a target: c" << endl;

            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost +  CNOT;
            gateCount = gateCount + 1;
        }

        else if((a[i] == 1) && (b[i] == 1) && (c[i] == 0)) //110 is in 100
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                b[j] = !b[j];
                }
            }
            cout << "CNOT control: a target: b" << endl;

            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost +  CNOT;
            gateCount = gateCount + 1;
        }

        else if((a[i] == 1) && (b[i] == 1) && (c[i] == 1)) //111 is in 100
        {
            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                c[j] = !c[j];
                }
            }
            cout << "CNOT control: a target: c" << endl;

            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }


            for(int j = i; j <= 7; j++) //apply CNOT
            {
                if(a[j])
                {
                b[j] = !b[j];
                }
            }
            cout << "CNOT control: a target: b" << endl;

            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }
            cost = cost +  (2*CNOT);
            gateCount = gateCount + 2;
        }

        else
        {
            break;
        }
        break;

        case 5:
        if(a[i] && b[i] && (c[i] == 0)) //when 110 is in the pos of 101. apply positive FRED with control in on top line (a)
        {
            //cout << "case 5: " << endl;


            for(int j = i; j <=7; j++)
            {
                if(a[j] == 1 && b[j] == 1)
            {
                c[j] = !c[j];
            }
            }
            cout << "Toffoli. Control: a and b. Target: c" << endl;
            for(int i = 0; i < num; i++)
            {
                cout << a[i] << " " << b[i] << " " << c[i] << endl;
            }

            for(int j = i; j <=7; j++)
            {
                if(a[j] == 1 && c[j] == 1)
            {
                b[j] = !b[j];
            }
            }
            cout << "Toffoli. Control: a and c. Target: b" << endl;

            cost = cost + (2 * TOF);
            gateCount = gateCount + 2;

            for(int i = 0; i < num; i++)
                {
                    cout << a[i] << " " << b[i] << " " << c[i] << endl;
                }
        }

        else if(a[i] && b[i] && (c[i] == 1)) //when 110 is in the pos of 101. apply positive FRED with control in on top line (a)
        {
            //cout << "case 5: " << endl;


            for(int j = i; j <=7; j++)
            {
                if(a[j] == 1 && c[j] == 1)
            {
                b[j] = !b[j];
            }
            }
            cout << "Toffoli. Control: a and c. Target: b" << endl;

            cost = cost + TOF;
            gateCount = gateCount + 1;

            for(int i = 0; i < num; i++)
                {
                    cout << a[i] << " " << b[i] << " " << c[i] << endl;
                }
        }

        else
            {
                break;
            }
//        if(b[i] && c[i]) //this condition will never occur
//        {
//
//        }
        break;

        case 6:
        if(a[i] && b[i] && (c[i] == 1)) //when 111 is in the pos of 110. apply positive FRED with control in on top line (a)
        {
            //cout << "case 5: " << endl;


            for(int j = i; j <=7; j++)
            {
                if(a[j] == 1 && b[j] == 1)
            {
                c[j] = !c[j];
            }
            }
            cout << "Toffoli. Control: a and b. Target: c" << endl;

            cost = cost + TOF;
            gateCount = gateCount + 1;

            for(int i = 0; i < num; i++)
                {
                    cout << a[i] << " " << b[i] << " " << c[i] << endl;
                }
        }
        break;
    }
    }
//    cout << endl << num << endl;

//    cout << endl;
//    for(int i = 0; i < num; i++)
//    {
//        cout << !a[i] << " " << !b[i] << " " << !c[i] << endl;
//    }
//    cout << endl;
//    for(int i = 0; i < num; i++)
//    {
//        cout << a[i] << " " << b[i] << " " << c[i] << endl;
//    }
    cout << endl;
    cout << "Quantum Cost: " << cost << endl;
    cout << "Gate Count: " << gateCount << endl;
    cout << endl;

    ostringstream outFileName;
    outFileName << "GC3x3QC_" << f << ".txt";
    ofstream out(outFileName.str().c_str(), ios::trunc|ios::out);
    out << gateCount << " " << cost;
    fin.close();
    out.close();
    }

    //cout << endl << endl << a[6] << b[6] << c[6] << endl;

    return 0;
}
