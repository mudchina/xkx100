// mengpo.c 孟婆

#include <ansi.h>
#include <login.h>
inherit NPC;

string *death_msg = ({
	HIB "孟婆说道：“孩子，你来啦？”\n\n" NOR,
	HIB "孟婆对你微笑着，说：“既然来了，就不要再想家了。”\n\n\n" NOR,
	HIB "孟婆说：“来到阴间，就要把阳间的事情尽数忘掉才好。”\n\n" NOR,
	HIB "孟婆说：“这碗茶能使你忘记过去的一切，快把它喝了吧。。。。”\n\n孟婆给你一碗茶。\n" NOR,

});

void create()
{
	set_name("孟婆", ({ "meng po" }) );
	set("long",@LONG
孟婆生于东汉末年，一生未曾婚嫁，守斋行善，直到八十多岁仍然
身体健朗，容貌仍似三四十岁一般，被乡里尊为神仙；后来她入深山
修炼道行，终于在一百三十岁时得道成仙。她升天后，玉皇大帝命令
她到阴间掌管阴司事务。
LONG);
	set("gender","女性");
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"孟婆轻轻地拍了拍你的肩膀，安慰你。\n",
		"孟婆说：“孩子，你是因为什么丧命的？告诉婆婆。”\n",
	}) );
	set("age", 1024);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	setup();
}

void init()
{
	remove_call_out("tea_give");
	call_out( "tea_give", 3, this_player(),0 );
}

void tea_give(object ob,int stage)
{
	object tea;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "tea_give", 3, ob, stage );
		return;
	}
	if( !objectp( present( GRN"mengpo tea"NOR ,ob ) ) && !objectp( present( GRN"mengpo tea"NOR , environment( this_object() ) ) ) )
	{
		tea = new(NOSTRUM_DIR"mengpotea");
		tea->move(ob); 
	}
}
int accept_fight(object me)
{
	command("sigh");
	write("孟婆道：“孩子，你真是不可救药了！”\n");
	kill_ob(me);
	me->fight_ob(this_object());
	return 1;
}

