#include "iostream"
using namespace std;

int main() {
    
    const int a=100,b=100;
    int n, mass_list[a][b],choose;
    
    cout << "How to get your rezult?\n\n1 - by list\n2 - by contiguity matrix\n3 - by incidence matrix\n";
    cin>>choose;
    
    switch (choose) {
        
        
        case 1: {
            cout << "Enter the quantity of tops => ";
            cin >> n;
            
            // INITIALIZATION WITH '0'
            
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    mass_list[i][j]=0;
                }
            }
            
            // VALUES ENTERING & CHECKING
            
            cout << "\nEnter values [with a gap] for 1-"<<n<< " tops of your graph\nENTER '0' AT THE END OF EACH ROW TO PASS TO THE NEXT TOP\n\n";
            
            for (int i=1; i<=n; i++) {
                
                cout << i <<" top -> ";
                
                for (int j=1; j<n; j++) {
                    
                    cin >> mass_list[i][j];
                    
                    if (mass_list[i][j]==0) {
                        break;
                    }
                    
                    if (mass_list[i][j]==i || mass_list[i][j]==mass_list[i][j-1] || mass_list[i][j]>n) {
                        cout << "Error! Please, re-enter last wrong value => ";
                        cin >> mass_list[i][j];
                        if (mass_list[i][j]==i || mass_list[i][j]==mass_list[i][j-1] || mass_list[i][j]>n) {
                            exit(0);
                        }
                    }
                }
            }
            
            // CONTIGUITY MATRIX
            
            int mass_sum[a][b];
            
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    mass_sum[i][j]=0;
                }
            }
            
            for (int i=1; i<=n; i++) {
                for (int j=1; j<n; j++) {
                    mass_sum[i][mass_list[i][j]]=1;
                }
            }
            
            cout << "\nContiguity matrix:"<<endl<<endl;
            
            for (int i=1; i<=n; i++) {
                
                if (i<10) {
                    cout << i <<" | ";
                }
                else {
                    cout << i <<"| ";
                }
                
                for (int j=1; j<=n; j++) {
                    cout << mass_sum[i][j]<<" ";
                }
                cout <<'\n';
            }
            
            // INCIDENCE MATRIX
            
            int mass_inc[a][b],f=1;
            
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    mass_inc[i][j]=0;
                }
            }
            
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (j>i) {
                        if (mass_sum[i][j]==1) {
                            mass_inc[i][f]=1;
                            mass_inc[j][f]=1;
                            f++;
                        }
                    }
                }
            }
            
            // Printing values
            
            cout << "\nIncidence matrix:"<<endl<<endl;
            
            cout <<"    ";
            
            for (int i=1; i<f; i++) {
                cout << "e"<<i<<"  ";
            }
            
            cout << '\n';
            
            for (int i=1; i<=n; i++) {
                
                if (i<10) {
                    cout << i <<" | ";
                }
                else {
                    cout << i <<"| ";
                }
                
                for (int j=1; j<f; j++) {
                    
                    if (j<=10) {
                        cout << " "<<mass_inc[i][j]<<"  ";
                    }
                    else {
                        cout << "  "<<mass_inc[i][j]<<"  ";
                    }
                    
                }
                
                cout << '\n';
            }
            
            cout << '\n';
            
            break;
        }
        
        
        
        case 2: {
            
            int sum[a][b], sum_list[a][b], d=1;
            
            cout << "\nEnter the quantity of tops => ";
            cin >> n;
            
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    sum[i][j]=0;
                    sum_list[i][j]=0;
                }
            }
            
            // CONTIGUITY MATRIX - ENTERING VALUES
            
            cout << "\nEnter your contiguity matrix:\nEACH VALUE SHOULD BE WITH A GAP \n"<<endl;
            
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    cin>>sum[i][j];
                    if (sum[i][j]!=0 && sum[i][j]!=1) {
                        cout << "Re-enter last wrong value!"<<endl;
                        cin >> sum[i][j];
                    }
                    if (sum[i][j]!=0 && sum[i][j]!=1) {
                        exit(0);
                    }
                }
            }
            
            for (int i=1; i<=n; i++) {
                d=1;
                for (int j=1; j<=n; j++) {
                    if (sum[i][j]==1) {
                        sum_list[i][d]=j;
                        d++;
                    }
                }
            }
            
            cout << "\nYour list: \n"<<endl;
            
            for (int i=1; i<=n; i++) {
                cout << i <<") -> ";
                for (int j=1; j<=n; j++) {
                    if (sum_list[i][j]!=0) {
                        cout << sum_list[i][j]<<" ";
                    }
                }
                cout <<'\n';
            }
            
            // INCIDENCE MATRIX
            
            int mass_inc[a][b],f=1;
            
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    mass_inc[i][j]=0;
                }
            }
            
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (j>i) {
                        if (sum[i][j]==1) {
                            mass_inc[i][f]=1;
                            mass_inc[j][f]=1;
                            f++;
                        }
                    }
                }
            }
            
            // Printing values
            
            cout << "\nIncidence matrix:"<<endl<<endl;
            
            cout <<"    ";
            
            for (int i=1; i<f; i++) {
                cout << "e"<<i<<"  ";
            }
            
            cout << '\n';
            
            for (int i=1; i<=n; i++) {
                if (i<10) {
                    cout << i <<" | ";
                }
                else {
                    cout << i <<"| ";
                }
                
                for (int j=1; j<f; j++) {
                    if (j<=10) {
                        cout << " "<<mass_inc[i][j]<<"  ";
                    }
                    else {
                        cout << "  "<<mass_inc[i][j]<<"  ";
                    }
                }
                cout << '\n';
            }
            
            cout << '\n';
            
            break;
        }
        
        case 3: {
            
            cout << "\nEnter the quantity of top's => ";
            cin >> n;
            
            int k;
            
            cout << "Enter the quantity of edges => ";
            cin >> k;
            
            int inc[a][b], sum[a][b], list[a][b];
            
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    sum[i][j]=0;
                    inc[i][j]=0;
                }
            }
            
            cout << "\nEnter your incidence matrix values:\nEACH VALUE SHOULD BE WITH A GAP \n"<<endl;
            
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=k; j++) {
                    cin >> inc[i][j];
                }
            }
            
            // CREATING THE CONTIGUITY MATRIX
            
            int f=1,d=1,rez[a][3];
            
            for (int i=1; i<=k; i++) {
                d=1;
                for (int j=1; j<=n; j++) {
                    if (inc[j][i]==1) {
                        rez[f][d]=j;
                        d++;
                    }
                }
                f++;
            }
            
            d=1;
            
            for (int i=1; i<=k; i++) {
                sum[rez[i][d]][rez[i][d+1]]=1;
                sum[rez[i][d+1]][rez[i][d]]=1;
            }
            
            // PRINTING THE CONTIGUITY MATRIX
            
            cout << "\nContiguity matrix:"<<endl<<endl;
            
            for (int i=1; i<=n; i++) {
                
                if (i<10) {
                    cout << i <<" | ";
                }
                else {
                    cout << i <<"| ";
                }
                
                for (int j=1; j<=n; j++) {
                    cout << sum[i][j]<<" ";
                }
                cout <<'\n';
            }
            
            // CREATING A LIST
            
            for (int i=1; i<=n; i++) {
                d=1;
                for (int j=1; j<=n; j++) {
                    if (sum[i][j]==1) {
                        list[i][d]=j;
                        d++;
                    }
                }
            }
            
            cout << "\nYour list: \n"<<endl;
            
            for (int i=1; i<=n; i++) {
                cout << i <<") -> ";
                for (int j=1; j<=n; j++) {
                    if (list[i][j]!=0) {
                        cout << list[i][j]<<" ";
                    }
                }
                cout <<'\n';
            }
            
            cout<<endl;
            
            break;
        }
        
        default: {
            cout << "Error value!"<<endl;
            exit(0);
            break;
        }
    }
    
    
    return 0;
}


