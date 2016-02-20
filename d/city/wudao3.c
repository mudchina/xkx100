// Room: /city/wudao3.c
// Date: Feb.28 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "武道场");
	set("long", @LONG
这里是三面环山，只有北面有条出口的一坪山间平地。山坡山阵阵
松涛哗哗作响，山脚下的平地绿草如茵，中间已经架起了个擂台，四周
一溜过去搭着凉棚，棚中桌椅杯盆俱全，看来比武大会快开始了。
    场中立有一面告示牌(gaoshi)。
LONG );
        set("outdoors", "yangzhouw");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"leitai"      : __DIR__"leitai",
		"northeast"   : __DIR__"wudao1",
		"northwest"   : __DIR__"wudao2",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("coor/x", -20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");

	add_action("do_quit","exercise");
	add_action("do_quit","dazuo");
	add_action("do_quit","exert");
	add_action("do_quit","yun");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","respirate");
	add_action("do_quit","tuna");
	add_action("do_quit","perform");
	add_action("do_quit","persuade");
	add_action("do_quit","quanjia");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_quit","teach");
	add_action("do_quit","jiao");
}

int do_quit(string arg)
{
	write(this_player()->query("name")+"，折腾个啥劲儿呀，专心看比武吧！\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object obj;
//	if ((dir == "leitai") && (!me->query_temp("leitai_allow")) && !wizardp(me))
//		return notify_fail("还没到你比武呢，别猴急上去。\n");
//	if ((dir == "leitai") && (me->query_temp("leitai_allow")))
	if (dir == "leitai")
	{
		me->delete_temp("leitai_allow");
		me->delete_temp("view_leitai");
		me->set("no_get", 1);
	}
        return ::valid_leave(me, dir);
}
string look_gaoshi()
{
	return 
HIR"\n\n                           
                 侠客行一百的比武大会
\n"HIY"
第一、每月的十五日晚十九时三十分举行比武大会。比赛地点设在扬州
      西门外武道场。
第二、比赛分组进行，每组比赛正式开始之前欲参加比武者请向当值巫
      师报名。分组如下：
      二十岁以下组 经验100万以下组 经验100万~300万组
      经验300万~500万组 经验500万~1000万组 经验1000万以上组
      如果某一组内只有一人报名参加，他就直接获得该组冠军。
第三、比武实行淘汰制。
      各组除决赛实行三局两胜制外，均为一场定胜负，胜者进入下一
      轮；三局两胜制，第一局比较兵器上的功夫，第二局在拳脚上决
      个高下，第三局自选。优胜者获得该组冠军。
第四、为使天下第一名实相符，允许使用现行所有武功，允许perform、
      powerup、enforce、poison等，但roar由于严重影响比武秩序，
      因此谢绝使用。违者停赛。
第五、比赛时所用兵器和防具请在擂台上的兵器架上自行拿取，经研究，
      禁止使用自铸兵器，禁止使用金丝甲、软猬甲、真丝宝甲，禁止
      使用伤害力超过50的兵器如敖拜匕首、倚天剑、伏魔刀等。
第六、比赛时请注意言行，犯众怒者、违反现场巫师安排者，取消其一
      年比赛资格。
"HIG"                                      侠客行  敬启
\n"NOR;
}