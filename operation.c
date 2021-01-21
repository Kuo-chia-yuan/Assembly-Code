#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "codeGen.h"
#include "lex.h"

int a=0;
void evaluateTree1(BTNode *root)
{
    if(root!=NULL){
        if (root->data == ASSIGN) {
            if(root->left->lexeme[0]!='x' && root->left->lexeme[0]!='y' && root->left->lexeme[0]!='z')
                evaluateTree1(root->left);
            evaluateTree1(root->right);
            printf("MOV ");
            if (root->left->lexeme[1] == 'x' || root->left->lexeme[1] == 'y' || root->left->lexeme[1] == 'z')
                printf("[%d] ", (root->left->lexeme[1] - 'x') * 4 + 12);
            else if (root->left->lexeme[0] == 'x' || root->left->lexeme[0] == 'y' || root->left->lexeme[0] == 'z')
                printf("[%d] ", (root->left->lexeme[0] - 'x') * 4);
            else
                printf("r%d ", root->left->val);
            printf("r%d\n", root->right->val);
        }
        else if (root->data == ADDSUB || root->data == MULDIV || root->data == LOGICAL || root->data == INCDEC) {
            evaluateTree1(root->left);
            evaluateTree1(root->right);
            if (root->data == ADDSUB) {
                if (root->lexeme[0] == '+')
                    printf("ADD r%d r%d\n", root->left->val, root->right->val);
                else
                    printf("SUB r%d r%d\n", root->left->val, root->right->val);
            }
            else if (root->data == MULDIV) {
                if (root->lexeme[0] == '*')
                    printf("MUL r%d r%d\n", root->left->val, root->right->val);
                else
                    printf("DIV r%d r%d\n", root->left->val, root->right->val);
            }
            else if (root->data == INCDEC){
                if(root->lexeme[0]=='+')
                    printf("ADD r%d r%d\n", root->left->val, root->right->val);
                else
                    printf("SUB r%d r%d\n", root->left->val, root->right->val);
            }
            else {
                if (root->lexeme[0] == '|')
                    printf("OR r%d r%d\n", root->left->val, root->right->val);
                else if(root->lexeme[0] == '&')
                    printf("AND r%d r%d\n", root->left->val, root->right->val);
                else
                    printf("XOR r%d r%d\n", root->left->val, root->right->val);
            }
            root->val = root->left->val;
            a = a - 1;
        }
        else{
            if(root->lexeme[1]=='x' || root->lexeme[1]=='y' || root->lexeme[1]=='z')
                printf("MOV r%d [%d]\n", a, (root->lexeme[1]-'x')*4+12);
            else if(root->lexeme[0]=='x' || root->lexeme[0]=='y' || root->lexeme[0]=='z')
                printf("MOV r%d [%d]\n", a, (root->lexeme[0]-'x')*4);
            else
                printf("MOV r%d %s\n", a, root->lexeme);
            root->val=a;
            a++;
        }
    }
    return;
}
int evaluateTree(BTNode *root) {
    int retval = 0, lv = 0, rv = 0;

    if (root != NULL) {
        switch (root->data) {
            case ID:
                retval = getval(root->lexeme);
                break;
            case INT:
                retval = atoi(root->lexeme);
                break;
            case ASSIGN:
                rv = evaluateTree(root->right);
                retval = setval(root->left->lexeme, rv);
                break;
            case ADDSUB:
            case MULDIV:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);
                if (strcmp(root->lexeme, "+") == 0) {
                    retval = lv + rv;
                } else if (strcmp(root->lexeme, "-") == 0) {
                    retval = lv - rv;
                } else if (strcmp(root->lexeme, "*") == 0) {
                    retval = lv * rv;
                } else if (strcmp(root->lexeme, "/") == 0) {
                    if (rv == 0)
                        error(DIVZERO);
                    retval = lv / rv;
                }
                break;
            case INCDEC:
                if(strcmp(root->lexeme, "++")==0)
                    retval = lv + rv;
                else if(strcmp(root->lexeme, "--")==0)
                    retval = rv - lv;
                break;
            default:
                retval = 0;
        }
    }
    return retval;
}
void printPrefix(BTNode *root) {
    /*if (root != NULL) {
        printf("%s ", root->lexeme);
        printPrefix(root->left);
        printPrefix(root->right);
    }*/
}
