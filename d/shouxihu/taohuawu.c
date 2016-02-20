// Room: /yangzhou/taohuawu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "桃花坞");
	set("long", @LONG
长堤春柳北端，为桃花坞故址，可惜此坞久废。废墟上新筑徐园，
园中有黄石迭砌的荷池，外有曲水，内有池塘，池水与湖水相通。过池
是馆轩，取杜甫“两个黄鹂鸣翠柳，一行白鹭上青天”之意，而称听鹂
馆。馆内遍种松柏、桃柳、红枫、紫薇，花坛满栽芍药。馆门抱柱悬挂
同治状元陆润庠楹联(lian)，外柱悬挂阮元楹联 (lian2)。北面澄鲜水
榭为画舫靠泊处，亦为远眺小金山最佳处。绕过徐园，立于小红桥，小
金山耸立，湖面陡然放开。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "shouxihu");
	set("no_clean_up", 0);
	set("item_desc", ([
		"lian" : "
        绿        红
        印        流
        苔        花
        痕        韵
        留        爱
        鹤        莺
        篆        簧
\n",
		"lian2" : "
        江        山
        波        色
        蘸        迎
        绿        人
        岸        秀
        堪        可
        染        餐
\n",
	]));
	set("exits", ([
		"northwest" : __DIR__"ouxiangqiao",
		"southdown" : __DIR__"pingtai",
		"south"     : __DIR__"changdi2",
		"north"     : __DIR__"xiaohongqiao",
		"west"      : __DIR__"yinxie",
		"east"      : __DIR__"chunboqiao",
	]));
	set("objects", ([
		"/d/city/npc/lady" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
