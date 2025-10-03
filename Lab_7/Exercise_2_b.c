

int evaluation(char str[]){

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] > 47 && str[i] < 57)
        {
            push(str[i]);
        }
        else if (check_sign){
            if (str[i] == '('){break;}
            int val_1 = ((int) pop())-48;
            int val_2 = ((int) pop())-48;
            switch (str[i])
            {
            case '+':
                push(val_1+val_2);
                break;
            case '-':
                push(val_1-val_2);
                break;
            case '*':
                push(val_1*val_2);
                break;
            case '/':
                push(val_1/val_2);
                break;
            case '^':
                push(pow(val_1,val_2));
                break;
            }
        }
    }
    return pop();
    
}