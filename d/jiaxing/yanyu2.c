// Room: /d/jiaxing/Yanyu2.c  烟雨楼二楼
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;

string look_bian();
int do_halloa(string arg);

void create()
{
        set("short", "烟雨楼二楼");
        set("long", @LONG
烟雨楼在南湖畔，四望临风，醺醺醉人。柳岸翻曳，禽噪起伏。湖
面轻烟薄雾，几尾小舟荡漾其间。半湖水里都浮着碧油油的菱叶，越女
轻歌，娇痴无那。你放眼观赏，美景无限，胸怀大畅之下只想大声喊叫
(halloa)。

    楼中立了一幅长匾(bian)，绞丝镶边，楠木为里，年代虽久，桐油
粉漆，犹自清新如昨。柱子上隐隐有些字迹（ziji）。
LONG );
        set("no_sleep_room",1);
        set("item_desc", ([
            "ziji" : "江南七怪叫板邱处机处。\n",
            "bian" : (: look_bian :),
        ]));

        set("exits", ([
            "down"     : __DIR__"yanyu",
        ]));
	set("no_clean_up", 0);
	set("coor/x", 1520);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	mapping myfam;
	
	add_action("do_halloa", "halloa");
	myfam = (mapping)me->query("family");
	if (!mapp(myfam) || !stringp(myfam["family_name"])) return 0;
	
	if (myfam["family_name"] == "白驼山派" && me->query_condition("ice_sting")
		&& me->query_condition("ice_sting") < 10) {
		message_vision(HIB"$N只觉得左臂越来越是肿大，情状凶险无比，再不救治就来不及了！\n", me);
		message_vision(HIG"忽听得背后一人说道：”小娃娃，知道厉害了吧！“，声音铿锵刺耳，\n", me);
		message_vision("$N吃了一惊，急忙转过身来，只见一个怪人，双手各持一块石头，以手为足，\n", me);
		message_vision("”钵，钵，钵“地走了过来，那人怪眼一翻：”小娃儿，要命的跟我来。“ \n", me);
		message_vision("说罢，双手一发劲，越上了屋顶。$N知道遇上了救星，大喜过望，连忙攀爬而上。\n"NOR, me);
		me->move(__DIR__"yanyu3");
	}
}

int do_halloa(string arg)
{
	object me = this_player();
	mapping myfam;
	
	if (!arg || arg != "义父") return 0;
	
	myfam = (mapping)me->query("family");
	
	if (!mapp(myfam) || !stringp(myfam["family_name"])) return 0;
	if (myfam["family_name"] == "白驼山派" && myfam["master_id"] == "ouyang feng") {
		message_vision(HIC"$N气沉丹田，长啸一声：“义父，你在哪里？”\n", me);
		message_vision("过了半晌，耳畔传来熟悉的“钵，钵，钵”的声响，欧阳锋从楼顶一跃而下。\n", me);
		message_vision("欧阳锋对着$N点了点头：”乖孩子，你又来学功夫了，跟我来吧！\n"NOR, me);
		me->move(__DIR__"yanyu3");
		return 1;
	} else  return notify_fail("叫虾米叫，你义父是谁？\n");
}

string look_bian()
{
        return
        "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "※※※※　　　                    　　　　　　　　　　　　※※※※\n"
        "※※※※　　　　            　西洲曲    　        　　　　※※※※\n"
        "※※※※　                                            　　※※※※\n"
        "※※※※　忆梅下西洲  折梅寄江北  单衫杏子红  双鬓鸦雏色　※※※※\n"
        "※※※※　西洲在何处  双桨摇头度  日暮伯劳飞  风吹乌桕树　※※※※\n"
        "※※※※　树下即门前  门中露翠钿  开门郎不至  出门采红莲　※※※※\n"
        "※※※※　采莲南塘秋  莲花过人头  低头弄莲子  莲子清如水　※※※※\n"
        "※※※※　置莲怀袖中  莲心彻底红  忆郎郎不至  仰首思飞鸿　※※※※\n"
        "※※※※　飞鸿满西洲  望楼上青楼  楼高望不见  尽日栏杆头　※※※※\n"
        "※※※※　栏杆十二曲  垂手明如玉  卷帘天自高  海水摇空绿　※※※※\n"
        "※※※※　海水梦悠悠  君愁我亦愁  南风如我意  吹梦到西洲　※※※※\n"
        "※※※※　　　　　　　　　　　                    　　　　※※※※\n"
        "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n";
}