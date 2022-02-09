#include <iostream>
#include <fstream>
#include <sstream>
#include <float.h>
#include <iomanip>


using namespace std;
double m_dblTstart = 0;
double m_dblh = 0.001;                                             // Defining variables, m_dblh is the step of intergration.
double m_dblDataSize = 500/m_dblh;
string m_sfilepath = "/Users/mohammedusmaan/Downloads/";





void oOutput(string sFileName, const string outputData)                 // Output Function
{

    ofstream Output;

    Output.open(m_sfilepath+sFileName);

    if (Output.is_open()){

        Output << outputData << "\n";

        cout << outputData;

    }

    Output.close();
}








double dblODE1(double y, double z)           // Function for the first ODE
{

   double a = - y - z;

    return a;
}


double dblODE2(double x, double a, double y)         // Function for the Second ODE
{

    double p = x + a * y;
    return p;
}


double dblODE3( double b, double z, double x, double c)         // Function for the third ODE
{
    double e = b + z * (x-c);

    return e;
}


void EvaluateIntegral(string sFileName,string SubFile, string SubFile2, double ConstA, double ConstB, double ConstC)  // Function for Evaluating the integral.
    {



    stringstream ssOutput;
    stringstream ssOutput1;
    stringstream ssOutput2;


    double dbloldXval = 1.0;
    double dbloldYval = 1.0;
    double dbloldZval = 0.0;
    double dblNewXVal = 0;
    double dblNewYVal = 0;
    double dblNewZVal = 0;
    double dbltk = 0;

    ssOutput << setprecision(3);
    ssOutput << fixed;
    ssOutput << "T_k"<< setw(17) << "x_0" << setw(17) << "y_0" << setw(16) << "z_0" <<"\n";
    ssOutput  <<"==================================================="<< "\n";
    for (int i = 0; i <= m_dblDataSize; i++) {


        dbltk = m_dblTstart + i * m_dblh;

        dblNewXVal = dbloldXval + m_dblh * dblODE1(dbloldYval, dbloldZval);
        dblNewYVal = dbloldYval + m_dblh * dblODE2(dbloldXval, ConstA, dbloldYval);
        dblNewZVal = dbloldZval + m_dblh * dblODE3(ConstB, dbloldZval, dbloldXval, ConstC);

        dbloldXval = dblNewXVal;
        dbloldYval = dblNewYVal;
        dbloldZval = dblNewZVal;

        if (dbltk >= 300){
            ssOutput << dbltk << setw(15) << dblNewXVal << setw(15) << dblNewYVal << setw(15) << dblNewZVal << "\n";
            ssOutput1 << dbltk << setw(15) << dblNewXVal << "\n";
            ssOutput2 << dblNewXVal << setw(15) << dblNewYVal << "\n";

        }


    }





       oOutput(sFileName, ssOutput.str());
       oOutput(SubFile, ssOutput1.str());
       oOutput(SubFile2, ssOutput2.str());

}

void Parameter1()                 // Function will pass the set Parameters in to the EvaluateIntegral, this is the same for the other Function
{

    double dbla = 0.2;
    double dblb = 0.2;
    double dblc = 2;
    string FileName = "./Parameter1.dat";
    string SubFile1 = "./Plot 1.dat";
    string SubFile2 = "./Plot 2.dat";
    EvaluateIntegral(FileName, SubFile1, SubFile2,dbla, dblb, dblc);

}

void Parameter2()
{
    double dbla = 0.2;
    double dblb = 0.2;
    double dblc = 3;
    string FileName = "./Parameter2.dat";
    string SubFile1 = "./Plot2 1.dat";
    string SubFile2 = "./Plot2 2.dat";
    EvaluateIntegral(FileName, SubFile1, SubFile2, dbla, dblb, dblc);

}

void Parameter3()
{
    double dbla = 0.2;
    double dblb = 0.2;
    double dblc = 10;
    string FileName = "./Parameter3.dat";
    string SubFile1 = "./Plot3 1.dat";
    string SubFile2 = "./Plot3 2.dat";
    EvaluateIntegral(FileName, SubFile1, SubFile2,dbla, dblb, dblc);

}



int main (){



    int Uinput = 1;

    while (Uinput > 0 ){
        cout << "Input a value for one of the following Parameters" << "\n";
        cout << "1 - First Parameter" << "\n";
        cout << "2 - Second Parameter" <<"\n";
        cout << "3 - Third Parameter" << "\n";
        cout << "0 - Exit Application" << "\n";
        cout << "Enter value here" << "  ";
        cin >> Uinput;
        if (cin.fail())
        {
            cout << endl << "Invalid input." << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            Uinput=1;

        }
        else{

            if (Uinput == 1)
            {
                Parameter1();
            }
            else if (Uinput == 2)
            {
                Parameter2();
            }
            else if (Uinput == 3)
            {
                Parameter3();
            }

            else {
                Uinput = 0;

            }

        }





}
}
