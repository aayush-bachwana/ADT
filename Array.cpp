#include <iostream>

using namespace std;

class Array
{
    int array[100]={0};
    int capacity;
    int size;

public:

    Array();

    //Operations--
    void append(int);
    void display(void);
    void swap(int*,int*);
    void insert(int,int);
    int search(int);
    void delete_(int);
    void pop(int);
    void reverse(void);
    void rotate_left(void);
    void shift_left(void);
    void rotate_right(void);
    void shift_right(void);

    //Functions--
    void maximum(void);
    void minimum(void);
    void sum(void);
    void average(void);
};


Array::Array()
{
    capacity=100;
    cout<<"Enter size of array--"<<endl;
    cin>>size;

    cout<<"Enter array values--"<<endl;

    for(int i=0;i<size;i++)
        cin>>array[i];
}

void Array::append(int value)
{
   array[size]=value;
   size++;
}

void Array::display()
{
    cout<<endl<<"Array is::"<<"\t";
    for(int i=0;i<size;i++)
        cout<<array[i]<<"\t";
    cout<<endl<<endl;
}

void Array::swap(int* p,int* q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

void Array::insert(int value,int key)
{
    if(key>=0 && key<size)
    {
        for(int i=size-1;i>=key;i--)
        {
            array[i+1]=array[i];
        }
        array[key]=value;
        size++;
    }
    else
        cout<<"Array index out of range!!!"<<endl;
}

int Array::search(int value)
{
    for(int i=0;i<size;i++)
    {
        if(array[i]==value)
            return i;
    }
    return -1;
}

void Array:: delete_(int value)
{
    int index_at_present=search(value);

    if(index_at_present>0)
        pop(index_at_present);
}

void Array:: pop(int index)
{
    for(int i=index;i<size;i++)
        array[i]=array[i+1];
    size--;
}

void Array::rotate_left(void)
{
    int temp;
    temp=array[0];

    for(int i=0;i<size-1;i++)
    {
      array[i]=array[i+1];
    }
    array[size-1]=temp;
}

void Array::shift_left(void)
{
    for(int i=0;i<size-1;i++)
    {
      array[i]=array[i+1];
    }
    array[size-1]=0;
}


void Array::shift_right(void)
{
    int i;
    for(i=size-1;i>0;i--)
    {
        array[i]=array[i-1];
    }
    array[i]=0;
}

void Array::rotate_right(void)
{
    int i;
    int temp=array[size-1];
    for(i=size-1;i>0;i--)
    {
        array[i]=array[i-1];
    }
    array[i]=temp;
}

void Array::reverse(void)
{
    int i,j;
    for(i=0,j=size-1;i<j;i++,j--)
        swap(&array[i],&array[j]);
}

void Array::maximum(void)
{
    int max_=array[0];

    for(int i=1;i<size;i++)
        if(array[i]>array[0])
            max_=array[i];

    cout<<"Maximum is::-\t"<<max_<<endl;
}

void Array::minimum(void)
{
    int min_=array[0];

    for(int i=1;i<size;i++)
        if(array[i]<min_)
            min_=array[i];

    cout<<"Minimum is::-\t"<<min_<<endl;
}

void Array::sum(void)
{
    int sum=0;

    for(int i=0;i<size;i++)
        sum+=array[i];

    cout<<"Sum is::-\t"<<sum<<endl;
}

void Array::average(void)
{
    int sum=0;
    float avg=0;

    for(int i=0;i<size;i++)
        sum+=array[i];

    avg=sum/size;
    cout<<"Average is::-\t"<<avg<<endl;
}


int main()
{
    Array arr;
    int query,index,value;
while(1)
 {
    cout<<endl<<"Enter the Operation you want to perform::"<<endl;

    cout<<"1. Append(value)"<<endl;
    cout<<"2. Insert(value,index)"<<endl;
    cout<<"3. Display()"<<endl;
    cout<<"4. Search(value)"<<endl;
    cout<<"5. Delete(value)"<<endl;
    cout<<"6. Pop(index)"<<endl;
    cout<<"7. Reverse()"<<endl;
    cout<<"8. Rotate left()"<<endl;
    cout<<"9. Shift left()"<<endl;
    cout<<"10. Rotate Right()"<<endl;
    cout<<"11. Shift Right()"<<endl;
    cout<<endl;
    cout<<"Enter the Function you want to perform::"<<endl;
    cout<<"12. Find maximum in array"<<endl;
    cout<<"13. Find minimum in array"<<endl;
    cout<<"14. Find sum of all elements in array"<<endl;
    cout<<"15. Find average of all in array"<<endl;
    cout<<endl;
    cout<<"|||||||||||||||||||||||||||||Press 0 to exit|||||||||||||||||||||||||||"<<endl;

    cin>>query;
 switch(query)
    {
    case 0:
        exit(1);
    case 1:
        cout<<"Enter value you want to append--"<<endl;
        cin>>value;
        arr.append(value);
        arr.display();
        break;
    case 2:
        cout<<"Enter value you want to insert for--"<<endl;
        cin>>value;
        cout<<"Enter index at which "<<value<<" to be insert--"<<endl;
        cin>>index;
        arr.insert(value,index);
        arr.display();
        break;
    case 3:
        arr.display();
        break;
    case 4:
        cout<<"Enter value you want to search for--"<<endl;
        cin>>value;
        arr.search(value);
        break;
    case 5:
        cout<<"Enter value you want to delete for--"<<endl;
        cin>>value;
        arr.delete_(value);
        break;
    case 6:
        cout<<"Enter index you want to remove--"<<endl;
        cin>>index;
        arr.pop(index);
        break;
    case 7:
        cout<<"Reversed array--"<<endl;
        arr.reverse();
        arr.display();
        break;
    case 8:
        cout<<"Left Rotation Successful!"<<endl;
        arr.rotate_left();
        arr.display();
        break;
    case 9:
        cout<<"Left Shifting Successful!"<<endl;
        arr.shift_left();
        arr.display();
        break;
    case 10:
        cout<<"Right Rotation Successful!"<<endl;
        arr.rotate_right();
        arr.display();
        break;
    case 11:
        cout<<"Right Shifting Successful!"<<endl;
        arr.shift_right();
        arr.display();
        break;

    case 12:
        arr.maximum();
        break;
    case 13:
        arr.minimum();
        break;
    case 14:
        arr.sum();
        break;
    case 15:
        arr.average();
        break;

    default:
        cout<<"Invalid Choice"<<endl;
    }
 }

    return 0;
}
