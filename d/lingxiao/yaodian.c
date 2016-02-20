// Room: /d/lingxiao/yaodian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "回春居");
	set("long", @LONG 
这就是凌霄城中医术最高明的戴大夫所开的回春居，一进这里，就
闻到一股刺鼻的药味，只见房中摆满了大大小小的箱笼、药柜。一名须
发皆白的老人坐在桌旁，正在替一人把脉。旁边的墙上贴着一张张条幅
(tiaofu)，都是被戴大夫治好了的病人送的。
LONG );
	set("no_fight",1);
	set("item_desc", ([
		"tiaofu" : "华佗再世，扁鹊重生。\n",
	]));
	set("objects", ([
		__DIR__"npc/daifu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"iceroad2",
	]));
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

