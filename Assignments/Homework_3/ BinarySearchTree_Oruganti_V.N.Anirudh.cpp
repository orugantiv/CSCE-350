/**********
 * NAME: V.N. ANIRUDH ORUGANTI
 * CLASS: CSCE 350
 * ASSIGNMENT: HOMEWORK #3 PART-B
**********/
#include <iostream>
#include <string>
#include <climits>
#include <exception>
#include <cfloat>
struct Node
{
    float key;
    Node *leftNode = NULL, *rightNode = NULL;
};

Node *insertNode(Node *&node, float key)
{
    // Checks if value for rootNode exits.
    if (node == NULL)
    {
        node = new Node();
        node->key = key;
    }
    // Input Key goes to right if input is greater.
    else if (key > node->key)
        node->rightNode = insertNode(node->rightNode, key);
    // Input Key goes to left if input is less.
    else
        node->leftNode = insertNode(node->leftNode, key);
    return node;
}

std::string searchNode( 
                        // Root Node
                        Node *&node, 
                        // Parent Node of Key
                        Node *&prevNode, 
                        // Key Node
                        Node *&numNode, 
                        // Search Key
                        float findNum, 
                        // Traversed Path
                        std::string path
                        )
{
    // If system couldn't find key
    if (node == NULL)
    {
        path = "***ERROR THE VALUE WAS NOT FOUND IN THIS TREE***\n" + path + "->ERROR";
        numNode = NULL;
    }
    // if system founds the key
    else if (node->key == findNum)
    {
        numNode = node;
        path += "->" + std::to_string(findNum);
    }
    // if system coundn't find the key and goes to right if key is greater 
    else if (findNum > node->key)
    {
        prevNode = node;
        numNode = node->rightNode;
        path = searchNode(node->rightNode, prevNode, numNode, findNum, path + "->" + std::to_string(node->key));
    }
    // if system coundn't find the key and goes to left if key is left 
    else
    {
        prevNode = node;
        numNode = node->leftNode;
        path = searchNode(node->leftNode, prevNode, numNode, findNum, path + "->" + std::to_string(node->key));
    }
    return path;
}

// Finds the smallest from given location of a node.
float findMinNode(  // Given Node
                    Node *node, 
                    // Sets the min to max float value.
                    float min = FLT_MAX)
{
    // itrs until left or right node is null
    if (node == NULL)
        return min;
    // Recursive search left and right to find lowest
    else if (node->key < min)
    {   min = node->key;
        min = findMinNode(node->leftNode, min);
        min = findMinNode(node->rightNode, min);
    }
    return min;
}
// This checks if a string is a floating point value 
bool checkDataType(const std::string &floatString)
{
    try
    {
        std::stof(floatString);
        return true;
    }
    catch (...)
    {
        return false;
    }
}
// Deletes a given node
std::string deleteNode(Node *&node, float keyNum)
{
    std::string deletionStatus = "";
    Node *prevNode = NULL, *keyNumNode = NULL;
    std::string path = searchNode(node, prevNode, keyNumNode, keyNum, "(Search Traversed Path)");
    // checks if there is nothing/NULL in a Node.
    if (keyNumNode == NULL)
        deletionStatus = path + "\nTHE VALUE YOU ENTERED COULDN'T BE DELETED :( ";
    // Deletion Case 1; if both left and right Nodes are Null
    else if (keyNumNode->rightNode == NULL && keyNumNode->leftNode == NULL)
    {
        // deleting rootNode
        if (prevNode == NULL)
        {
            delete node;
            deletionStatus = "The number \"" + std::to_string(keyNum) + "\" has been found and deleted.";
            node = NULL;
            goto JustDelete;
        }
        else if (prevNode->leftNode == NULL)
        {
            prevNode->rightNode = NULL;
        }
        else if (prevNode->rightNode == NULL)
        {
            prevNode->leftNode = NULL;
        }
        else if (prevNode->leftNode->key == keyNum)
        {
            prevNode->leftNode = NULL;
        }
        else if (prevNode->rightNode->key == keyNum)
        {
            prevNode->rightNode = NULL;
        }
        delete keyNumNode;
        deletionStatus = "The number \"" + std::to_string(keyNum) + "\" has been found and deleted.";
    }
    // Case 2; if only one of left or right nodes are Null.
    else if (keyNumNode->rightNode == NULL || keyNumNode->leftNode == NULL)
    {
        // if right node is not null, it switchs the key of childens,copys left and right node addr and deletes right node.
        if (keyNumNode->rightNode != NULL)
        {
            Node *temp = keyNumNode->rightNode;
            keyNumNode->key = temp->key;
            keyNumNode->leftNode = temp->leftNode;
            keyNumNode->rightNode = temp->rightNode;
            delete temp;
        }
        // Else left Node, it switchs the key of childens,copys left and right node addr and deletes right node.

        else
        {
            Node *temp = keyNumNode->leftNode;
            keyNumNode->key = temp->key;
            keyNumNode->leftNode = temp->leftNode;
            keyNumNode->rightNode = temp->rightNode;
            delete temp;
        }
        // Confirmation msg
        deletionStatus = "The number \"" + std::to_string(keyNum) + "\" has been found and deleted.";
    }
    // Case 3; if there values for both childern righ and left node.
    else if (keyNumNode->rightNode != NULL && keyNumNode->leftNode != NULL)
    {

        float minValue = findMinNode(keyNumNode->rightNode);
        deleteNode(keyNumNode, minValue);

        keyNumNode->key = minValue;
        deletionStatus = "The number \"" + std::to_string(keyNum) + "\" has been found and deleted.";
    }
JustDelete:
    return deletionStatus;
}

// Recursive funtion that ensures there are no memory leaks by deleting parentNodes. 
void deleteMemory(Node *&node)
{
    if (node == NULL)
        return;
    else if (node != NULL)
    {
        deleteNode(node, node->key);
        deleteMemory(node);
    }
}

int main()
{
    Node *rootNode = NULL, *preKeyNode = NULL, *keyNode = NULL;
    float input = 0;
    std::string inputVal = "";

    /************************ USER PROMT **********************************/
    while (1)                                           
    {
        std::cout << "***CHOOSE ONE OF THE OPTIONS BELOW***\n"
                  << "\t To insert a node enter 1\n"
                  << "\t To search a node enter 2\n"
                  << "\t To delete a node enter 3\n"
                  << "***ENTER ANYTHING ELSE TO EXIT***" << std::endl;
        std::cin >> inputVal;

        if (!(checkDataType(inputVal)))
        {
            std::cout << "***EXITING***" << std::endl;
            break;
        }
        else
        {
            input = std::stof(inputVal);
        }
        if (input == 1)
        {

            std::cout << "PLEASE ENTER THE VALUE(float) YOU WANT TO INSERT." << std::endl;

            std::cin >> inputVal;
            if (!(checkDataType(inputVal)))
            {
                std::cout << "***INCORRECT DATA TYPE EXITING***" << std::endl;
                break;
            }
            else
            {
                input = std::stof(inputVal);
            }

            insertNode(rootNode, input);
            std::cout << "-------------------------------------------------------------------" << std::endl;
            std::cout << "THE Value \"" << inputVal << "\" YOU ENTERED WAS INSERTED" << std::endl;
            std::cout << "-------------------------------------------------------------------" << std::endl;
        }
        else if (input == 2)
        {
            std::cout << "PLEASE ENTER THE VALUE(float) YOU WANT TO SEARCH." << std::endl;

            std::cin >> inputVal;
            if (!(checkDataType(inputVal)))
            {
                std::cout << "***INCORRECT DATA TYPE  EXITING***" << std::endl;
                break;
            }
            else
            {
                input = std::stof(inputVal);
            }

            std::cout << "-------------------------------------------------------------------" << std::endl;
            std::cout << searchNode(rootNode, preKeyNode, keyNode, input, "\n(Search Traversed Path)") << std::endl;
            std::cout << "-------------------------------------------------------------------" << std::endl;
        }
        else if (input == 3)
        {
            std::cout << "PLEASE ENTER THE VALUE(float) YOU WANT TO DELETE." << std::endl;

            std::cin >> inputVal;
            if (!(checkDataType(inputVal)))
            {
                std::cout << "***INCORRECT DATA TYPE  EXITING***" << std::endl;
                break;
            }
            else
            {
                input = std::stof(inputVal);
            }

            std::cout << "-------------------------------------------------------------------" << std::endl;
            std::cout << deleteNode(rootNode, input) << std::endl;
            std::cout << "-------------------------------------------------------------------" << std::endl;
        }
        else
        {
            std::cout << "***EXITING***" << std::endl;
            break;
        }
    }
    /************************ END OF USER PROMT **********************************/


    // Deletes values in rootNode.
    deleteMemory(rootNode);
}