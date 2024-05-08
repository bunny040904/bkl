#include<iostream>
#include<queue>
using namespace std;
class Tree //The class encapsulates the functionality related to a binary tree data structure.
 {
 typedef struct node //This line defines a nested structure within the Tree class.
 //typedef is used to create an alias for a data type, making it easier to use and understand.
{
char data[10];//declares array named data capable of holding 10 characters.It's used to store data associated with each node in the binary tree.
struct node *left;// declares pointer named left that points to another node.It's used to store address of left child node in the binary tree.
struct node * right;
}btree;//typedef is used to define btree as an alias for the structure node
 public:
btree *New,*root;//declares two public member variables: New and root.This declares a pointer variable named New, which is of type btree*
// This declares another pointer variable named root, also of type btree*. It is likely used to store the address of the root node of the binary tree.
Tree();//The constructor is likely used to initialize the member variables of the Tree class, such as root and New.
//automatically called when an object of the class is created.
 void create(); //The create() function is likely used to create a new node and insert it into the binary tree.
 void insert(btree *root,btree *New);//insert() function is used to insert a new node (New) into the binary tree.
//It takes two arguments: a pointer to the root node of the tree (root) and a pointer to the new node to be inserted (New).
 void display();
 };
Tree::Tree() //This is the definition of the constructor 
 {
 root=NULL;//This line initializes the root pointer to NULL.
//It ensures that when a Tree object is created, its root pointer starts as NULL, indicating an empty tree.
 }
void Tree::create() //This is the definition of the member function
 {
 New=new btree;//his line allocates memory for a new node using dynamic memory allocation (new)
 // It creates a new node of type btree  and assigns its address to the pointer New.
 New->left=New->right=NULL;//This line initializes the left and right pointers of the newly created node to NULL, indicating that it has no child nodes yet
cout<<"\n\tEnter the Data: ";//hese lines prompt the user to input data for the new node and store it in the data member of the New node.
cin>>New->data;
 if(root==NULL)//This condition checks if the root pointer of the binary tree is NULL, indicating that the tree is empty.
{
root=New;//f the root pointer is NULL, meaning the tree is empty, the root pointer is assigned to point to the new node (New)
}
 else
 {
insert(root,New);
 }
 }
void Tree::insert(btree *root,btree *New)//root, a pointer to the current node where insertion is being considered, and New, a pointer to the new node to be inserted.
//It prompts the user to choose whether to insert the new node as the left child or the right child of the current node (root).
 {
 char ans;
cout<<"\n\t"<<New->data<<" Want to Insert at "<<root->data<<" at Left(L) OR Right(R)";
//The prompt includes the data of the new node (New->data) and the data of the current node (root->data) to provide context for the user.
cin>>ans;
 if(ans=='L'||ans=='l')
 {
 if(root->left==NULL)
root->left=New;
 else
 insert(root->left,New);
}
 else
 {
 if(root->right==NULL)
root->right=New;
 else 
 insert(root->right,New);
}
 } 
void Tree::display()//displaying the binary tree in a level-wise (BFS - Breadth-First Search) traversal manner.
{
int i=1;
 if(root==NULL)
 {
cout<<"\n NULL Tree";
 return;
 }
 queue<btree *> q;//This part initializes a queue named q to perform BFS traversal.
q.push(root);//The root node is pushed into the queue to start the traversal from the root.
cout<<"\n\tLevelwise(BFS) Traversal\n";
 while(q.empty()==false)//while loop continues as long as the queue q is not empty, indicating that there are still nodes to process in the tree.
 {
btree *node=q.front();//The front element of the queue, representing the current node being processed, is accessed and stored in the pointer variable node.
 if(i==1)
cout<<node->data<<"\n";
 if(i==2)
cout<<node->data<<"\t";
 if(i==3)
cout<<node->data<<"\n";
 if(i==4||i==5||i==6||i==7)
 //f i is 1, the node's data is printed followed by a newline (\n).
//If i is 2, the node's data is printed followed by a tab character (\t).
//If i is 3, the node's data is printed followed by a newline (\n).
//If i is 4, 5, 6, or 7, the node's data is printed followed by a tab character (\t).
cout<<node->data<<"\t";
i++;//The variable i is incremented in each iteration to track the position of the node in the level-wise traversa
q.pop();//After processing the current node (node), the next step is to dequeue it from the queue (q.pop()), as it has been processed.
 if(node->left!=NULL)//Then, it checks if the current node has a left child (node->left != NULL). If it does, the left child is enqueued into the queue (q.push(node->left)).
q.push(node->left);
 if(node->right!=NULL)
q.push(node->right);
//the children of the current node are processed in subsequent iterations of the while loop, allowing the BFS traversal to continue level by level through the binary tree.
 }
}
int main()
 {
 Tree tr;//Creates an instance of the Tree class named tr
 int i=0;
 do//Starts a do-while loop
 {
 if(i==0)
 {
cout<<"\n\tEnter Chapter Name";//Prompts the user to enter a chapter name
tr.create();//Calls the create() method of the Tree instance tr to create a new chapter nod
i++;
 }
 if(i==1||i==2)
 //This part checks if i is equal to 1 or 2. If it is, the program prompts the user to enter a section name using cout, and then calls the create() method 
 {
cout<<"\n\tEnter Section Name";
tr.create(); //Calling the create() method of the Tree instance tr to create a new section node
i++;
 }
 if(i==3||i==4||i==5||i==6)//the program prompts the user to enter a sub-section name using cout.
 {
cout<<"\n\tEnter Sub-Section Name";
tr.create(); //his part calls the create() method of the tr instance to create a new node in the tree.
i++;
 }
 if(i==7)
 //This part checks if i is equal to 7. If it is, meaning all nodes have been created (1 chapter, 2 sections, and 4 sub-sections), it proceeds to display the tree.
 {
cout<<"\n tree is:";
tr.display();//It calls the display() method of the tr instance to display the tree in a level-wise (BFS) traversal manner.
 break; //it breaks out of the loop to exit the program.
 }
}while(1);
//his part of the code forms an infinite loop (while(1)), ensuring that the program continues to execute indefinitely until it encounters a break statement.
//The loop continues until the break statement inside the if(i==7) condition is executed.
 }
