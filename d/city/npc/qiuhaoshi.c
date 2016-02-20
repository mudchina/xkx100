//Npc : qiu_haoshi.c

inherit NPC;
#include <ansi.h>

string ask_room1();
string ask_room2();

void create()
{
    set_name( YEL "仇好石" NOR, ({"qiu haoshi", "qiu", "haoshi"}) );
    set( "title", "扬州容膝园主人" );
    set( "age", 52 );
    set( "int", 30 );
    set( "con", 26 );
    set( "per", 18 );
    set( "attribute", "peaceful" );

    set( "long", @LONG
仇好石是扬州的治园名家，据说几个著名的园子都出自他的手小。
他个子不高，脑袋却是极大，如墨刷的眉毛，小小的眼睛，大大
的鼻子，生就一副奇相。
LONG
    );
    set( "combat_exp", 10000 );
    set_skill( "literate", 100);

    set( "inquiry", ([
        "小玲珑山馆" : (: ask_room1 :),
        "杨府" : (: ask_room1 :),
        "郡圃" : (: ask_room2 :),
        "官衙后院" : (: ask_room2 :),
        "酒" : "我平生除酒外别无所好。\n",
        "喝酒" : "我平生除酒外别无所好。\n",
        "容膝园" : "呵呵，一个小园子了。\n",
        "扬州" : "天下三分明月夜，无奈二分在扬州，哈哈。。。",
    ]) );
	set("chat_chance", 3);
	set("chat_msg", ({
        "。。。仇好石看了你一眼，却什么也不说。",
        "你为何来烦我？",
        "何必把时间浪费在我这样一个老头子身上呢？",
        "唉。。仇好石长叹一声，转身又开始喝酒了。"
    }) );
    setup();
    carry_object(CLOTH_DIR"jinduan")->wear();
}

int accept_object( object me, object ob )
{
    if ( userp(ob) ) return 0;
    if ( ob->query("name") == "通州雪酒" )
    {
        remove_call_out( "accepted" );
        call_out( "accepted", 1, me );
        return 1;
    }
}

void accepted(object me)
{
    command( "haha" );
    command( "tell " + me->query("id") + " 你是任何得知我最好此酒？\n" );
    command( "en" );
    command( "tell " + me->query("id") + " 对于你的疑惑，我当知无不言。\n" );
    command( "haha " + me->query("id") );
    command( "drink skin" );
    me->set_temp( "can_ask_qiu" );
}

string ask_room1()
{
    if ( this_player()->query( "can_ask_qiu" ) )
    {
        command( "say 小玲珑山馆最有意思的地方就是疏峰馆了，不过\n"
         + "在我设计好后据说杨先生有改了一下，我却没看出来。\n"  );
        return "别的地方，你可以去看看，看看老夫我的治园手艺如何。";
    }
    else
        return "小玲珑山馆是我设计的。";
}

string ask_room2()
{
    if ( this_player()->query( "can_ask_qiu" ) )
    {
        command( "say 郡圃的外墙都用花窗、漏窗，也不高，也不怕贼闯入，呵呵！\n"
         + "不过官衙重地一般的贼子不敢闯入的。\n" );
        return "郡圃一般人可都进不去的。\n";
    }
    else
        return "郡圃乃是前任知州大人托我设计的。\n";
}


