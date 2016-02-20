// king.c

#include <ansi.h>
inherit NPC;

string *answer_msg =({
"不错，看在你平日的积德，加上你近日的磨练，就饶你这一次，你去见见判官吧。\n",
"嗯，你的罪孽已经差不多了，在过一段时间就可以了。\n",
"你心中积恶还未洗清，不能回家。",
"你罪孽深重，还是先等着吧。",
"哼，你孽似海深，还是老实点，多受些苦吧。",
"",//万一有人是300，就是这行。
});
string ask_me();

void create()
{
	set_name(HIW "酆都冥府大帝" NOR, ({ "ming king","king" }) );
	set("long",HIW @LONG
岱泰山乃天帝之孙，群灵之府，主世界人民官职生死贵贱等事，定生死簿，辖天下众
生，驭冥府群鬼。
LONG NOR);
	set("gender","男性");
	set("str",1000);
	set("nickname",HIR "阎罗冥王" NOR);
	set("title",GRN"天"RED"齐"YEL"仁"BLU"圣"CYN"大"MAG"生"WHT"敬"BLK"道"HIW"东岳大帝"NOR);            
	set("attitude", "peaceful");
	set("age", 102400000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("max_neili",100000);
	set("neili",100000);
	set("inquiry",([
		"回家":(:ask_me:),
	]) );
	setup();
}

string ask_me()
{
	int rein_time, mud_age, i;
	object who;
	who=this_player();
	if(who->query("age")<=15)
		return "咦？你这么小年纪，怎么会跑到这里来？";
	mud_age=(int)who->query("mud_age");
	rein_time=(int)(who->query("PKS") * 20) + (int)(who->query("MKS") / 10);
	i=rein_time-mud_age;
	i=i>=0?i:0;
	i/=60;
	if(i>=4)
	{
		command("heng");
		i = 4;
	}
	else if(i<=0)
	{
		command("nod");
		i = 0; 
	}
	return answer_msg[i];
}
