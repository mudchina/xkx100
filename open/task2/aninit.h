// aninit.h 定义杀手检查，自己消失的时间
#include <ansi.h>
#define A_TIME 20

string * shot_msg = ({
	"蓦地，街边上一个看来毫不起眼的$N突然冲了出来！\n",
	"这是个热闹所在，一个$N笑嘻嘻冲着$n迎了上来，似乎要交给$n什么东西。\n",
	"街角上一个$N本来在那里懒洋洋地晒着太阳，突然象离弦之箭般跃进身来。\n",
	"一个$N站在街心正在吆喝着什么，忽然转眼看见了$n，转身冲了过来！\n",
	"一个很平常的$N站在那里，脸上木然地没什么表情。\n",
	"街面上站着一个$N，嘴里嘟囔着什么话，结果看见$n就大叫一声扑了过来。\n",
});

string * name_msg = ({
	"流氓",
	"进香客",
	"道士",
	"行者",
	"挑夫",
	"家丁",
	"官兵",
	"行人",
	"乞丐",
	"百姓",
	"卖花姑娘",
	"老船夫",
	"趟子手",
	"铁匠",
	"小贩",
	"刀客",
	"剑客",
	"游方和尚",
	"江湖豪客",
});

string * long_id = ({
	"liu mang",
	"jinxiang ke",
	"dao shi",
	"xing zhe",
	"tiao fu",
	"jia ding",
	"guan bing",
	"xing ren",
	"qi gai",
	"bai xing",
	"flower girl",
	"lao chuanfu",
	"tangzi shou",
	"tie jiang",
	"xiao fan",
	"dao ke",
	"jian ke",
	"seng ren",
	"jianghu haoke",
});

string * short_id = ({
	"lm",
	"jk",
	"ds",
	"xz",
	"tf",
	"jd",
	"gb",
	"xr",
	"qg",
	"bx",
	"fg",
	"lc",
	"ts",
	"tj",
	"xf",
	"dk",
	"jk",
	"sr",
	"jh",
});

string * weapon_msg = ({
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/chuidutong",
	__DIR__"obj/sheerkou",
});

void init()
{
	remove_call_out("do_check");
	call_out("do_check", 0);
	remove_call_out("do_wait");
	call_out("do_wait",A_TIME);
}

void do_check()
{
	object me = this_object();
	object ob;

	if (! living(me) || me->fighting() )
	{
		remove_call_out("do_check");
		call_out("do_check",0);
	}
	else
	{
		if( !ob = present("ren zhi",environment(me)) || ! living(me) || me->is_fighting())
		{
			remove_call_out("do_check");
			call_out("do_check",0);
		}
		else
		{
			message_vision(HIG+shot_msg[random(sizeof(shot_msg))]+NOR,me,ob);
			command("shot "+ob->query("id"));
			ob -> add("combat_num",1);
			message_vision(HIW"\n当你定过神来再找那个$N，却已经消失得无影无踪了。\n"NOR,me);
			destruct(me);
		}
	}
}

void do_wait()
{
	object ob;
	object me = this_object();

	if (me->is_fighting() || !living(me) )
	{
		remove_call_out("do_wait");
		call_out("do_wait",A_TIME);
	}
	else
	{
		message_vision("$N自言自语地说道：看来那个人不会来了，我还是回去吧。\n$N悄没声息地向远处走了开去。\n",this_object());
		destruct(me);
	}
}

