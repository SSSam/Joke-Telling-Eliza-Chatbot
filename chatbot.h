// chatbot.h
// Your chatbot class goes here. Make sure it works with chatbot_driver.cpp.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std; 

class Chatbot{
  public:
  string botname;
  int greetfirst=0;
  int len;
  string userinput;
  int knownameflag=0;
  string username;
  string name;
  Chatbot(string);
  string tell(string);
  string get_name();
  string get_reply();
};

Chatbot::Chatbot(string name){
  botname=name;
}

string Chatbot::tell(string input){
  userinput=input;
  len=userinput.length();
  return userinput;
}

string Chatbot::get_name(){
  return botname;
}


using namespace std;
string Chatbot::get_reply(){
  string botresp = "";
  if(Chatbot::userinput==""){
    return botresp;
  }

  int greetflag=0;
  vector<std::string> greetkey{
    "hi", "hello","Hello", "Hey", "Hi", "wassup"
  };
  for(const auto& keyword: greetkey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      greetflag=1;
      greetfirst=1;
    }
  }
  
  if(greetfirst==0){
    string nohi[]{
      "Not even a HELLO? ","Welp...Hi... No hello?",
      "Hey stranger :))", "Hmmm... Some greetings first?"
    };
    int n = rand() % (sizeof(nohi)/sizeof(*nohi));
    botresp = nohi[n];
    greetfirst=1;
    return botresp;
  }



  if(greetflag==1){
    string greet[] = {
      "hello","Hello, how are you doing? ",
      "How was your day? ",
      "Hi there~!! How are you? ",
      "Wassup? ",
      "How's it going? "
    };
    int n = rand() % 5;
    botresp = greet[n];
    greetflag=0;
    return botresp;
  }

  int infoflag=0;
  vector<std::string> infokey{
    "what is your name","your name"
  };
  for(const auto& keyword: infokey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      infoflag=1;
    }
  }
  if(infoflag==1){
    cout<<"Chatty> I am Chatty, and I talk a lot :)) \n Chatty> And what is your name? "<<endl;
    cin>>username;
    Chatbot::knownameflag=1;
    botresp= "That's a great name, ";
    botresp=botresp.append(username);
    botresp=botresp.append(" What's your hobby ?");
    infoflag=0;
    return botresp;
  }

  int howruflag=0;
  vector<std::string> howrukey{
    "how are you","How are you", "How was your day",
    "How ar you doing", "How's it going?"
  };
  for(const auto& keyword: howrukey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      howruflag=1;}
  }
  if(howruflag==1){
    string howru[]{
      "Doing alright, How was your day?",
      "All good, What about you?",
      "I'm doing alright, you?",
      "Just chilling, what are you up to?",
      "Nothing much! Wanna hear a joke? Enter JOKE"
    };
    int n = rand() % (sizeof(howru)/sizeof(*howru));
    botresp = howru[n];
    howruflag=0;
    return botresp;
  }

  

 int jokeflag=0;
  vector<std::string> jokekey{
    "joke", "JOKE"
  };
  for(const auto& keyword: jokekey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      jokeflag=1;
    }
  }
  if(jokeflag==1){
    string joke[] = {
            "I don't trust stairs. They're always up to something.",
      "What do you call someone with no body and no nose? \n \n Nobody knows.",
      "How does a penguin build its house?\n \n Igloos it together.",
      "What do you call cheese that isn't yours? \n \n Nacho cheese.",
      "Why did the math book look so sad?\n \n Because of all of its problems!",
      "I just lost 20% of my couch \n \n Ouch!!",
      "My friend can't afford his water bill, so I send him a \n \n 'Get well soon card'.",
      "I was arrested for stealing cooking utensil \n\n But it was worth the whisk.",
      "I went to the store and pick up 8 cans of sprite. But when I got home, \n\n I realize I'd only picked 7up",
      "I spent 10 mins trying to remember what the opposite of 'night' was \n\n In the end I had to call it a day...",
      "It wasn't much fun when I broke my neck last year. \n\n But now I can look back and laugh.",
      "Just got the job as the senior director of the Old Mcdonald farm \n\n I'm now the CIEIO.",
      "My wife is really mad at the fact that I have no sense of direction. \n\n So I packed up my stuff and right!",
      "Why don't eggs tell jokes? \n\n They'd crack each other up.",
      "Why couldn't the bicycle stand up by itself? \n\n It was two tired.",
      "Why can't a nose be 12 inches long?\n\n Because then it would be a foot.",
      "How do you make holy water? \n\n You boil the hell out of it.",
      " I’m reading a book about anti-gravity. \n\n It’s impossible to put down.",
      "Justiceis a dish best served cold.\n\n If it were served warm it would be justwater."

    };
    int n = rand() % (sizeof(joke)/sizeof(*joke));
    botresp = joke[n];
    jokeflag=0;
    return botresp;
  }

  int laughflag=0;
  vector<std::string> laughkey{
    "ha ha","haha", "funny", "lol", "lmao"
  };
  for(const auto& keyword: laughkey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      laughflag=1;}
  }
  if(laughflag==1){
    string laugh[]{
      "HAHA, I know right. It was funny",
      "Aw, glad you like the joke :))",
      "HAHAHAHAHAHHAHAHA LMAO",
      "IKR!! HAHAHA, I was so lost when I heard it the first time."
    };
    int n = rand() % (sizeof(laugh)/sizeof(*laugh));
    botresp = laugh[n];
    laughflag=0;
    return botresp;
  }

  int qflag=0;
  vector<std::string> qkey{
    "why", "what", "how", "where", "when"
  };
  for(const auto& keyword: qkey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      qflag=1;
    }
  }
  if(qflag==1){
    string q[] = {
      "Have you ask others about that?",
      "Why do you think that way?",
      "Oh, do you really think that?",
      "What do you think?",
      "What knid of answer do you expect?",
      "What do you really want to know?"
    };
    int n = rand() % 5;
    botresp = q[n];
    qflag=0;
    return botresp;
  }

  int uflag=0;
  vector<std::string> ukey{
    "you","are you", "do you"
  };
  for(const auto& keyword: ukey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      uflag=1;
    }
  }
  if(uflag==1){
    string u[] = {
      "Let's not talk about me, ask me other question.",
      "Me? I think we are talking about you here",
      "Let's move on to other topic, shall we? How about enter JOKE"
    };
    int n = rand() % 5;
    botresp = u[n];
    uflag=0;
    return botresp;
  }

  int iflag=0;
  vector<std::string> ikey{
    "I ", "i ", "i want ", "I need ", "I like ", "I am"
    };
    int ipos=0;
  for(const auto& keyword: ikey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      ipos=pos;
      iflag=1;}
    }
    if(iflag==1){
      string i[]{
        "why do you ", "What makes you think that you ", "Oh... interesting, what is the reason behind you ", "Ok.. imagine you already ", "So your saying you "
      };
      int n = rand() % (sizeof(i)/sizeof(*i));
      botresp = i[n];
      botresp=botresp.append(Chatbot::userinput, ipos+2,10000);
      iflag=0;
      return botresp;
    }
  int agreeflag=0;
  vector<std::string> agreekey{
    "yes","sure", "why not", "ok", "fine", "good"
  };
  for(const auto& keyword: agreekey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      agreeflag=1;}
  }
  if(agreeflag==1){
    string agree[]{
      "Are you sure about that? ",
      "NIce, So do we have an agreement on that?",
      "Oh, perfect~ Good to hear it, tell me more~"
    };
    int n = rand() % (sizeof(agree)/sizeof(*agree));
    botresp = agree[n];
    agreeflag=0;
    return botresp;
  }

  int noflag=0;
  vector<std::string> nokey{
    "no", "NO", "Nah", "Not", "nope", "negative"
  };
  for(const auto& keyword: nokey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      noflag=1;
    }
  }
  if(noflag==1){
    string no[] = {
      "Are you saying NO just to be negative?",
      "Why not?",
      "Is there anything that didn't please you?",
      "Why do you think that way?",
      "Is there a reason behind you saying NO?",
      "Are you offended?",
      "I'm sorry to hear that, but things don't always go your way.",
    };
    int n = rand() % 5;
    botresp = no[n];
    noflag=0;
    return botresp;
  }

  int byeflag=0;
  vector<std::string> byekey{
    "bye", "Bye", "See you", "good bye", "byebye"
  };
  for(const auto& keyword: byekey){
    int pos= Chatbot::userinput.find(keyword);
    if(pos!=-1){
      byeflag=1;
    }
  }
  if(byeflag==1){
    string bye[] = {
      "Oh... you gotta go? Bye ",
      "Alright, I'm always here to talk, good bye ",
      "okiedokee, bye bye "
    };
    int n = rand() % 5;
    botresp = bye[n];
    byeflag=0;
    if (Chatbot::knownameflag==1){
      return botresp.append(username);
    }
    return botresp;
  }

  else{
    string idk[]={
      "ok... Do u wanna hear a joke? Enter joke",
      "Maybe~~ it's your choice, how about a joke? Enter JOKE",
      "Welp, whatever you say~ How about a joke? Enter JOKE",
      "You bet! Wanna haer a joke? Enter JOKE",
      "Indeed! Wanna hear a joke then? Enter JOKE"
    };
    int n = rand() % (sizeof(idk)/sizeof(*idk));
      botresp = idk[n];
  }
  return botresp;
}