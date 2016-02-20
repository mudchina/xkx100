// Room: /d/wuxi/songhe2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "松鹤楼二楼");
	set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边
吃喝边作交易。这里也是城里举办喜宴的最佳场所。你站在楼上临街眺
望，可看见南长街上热闹的场景。东面是小河弯弯，连绵而过。向北可
以隐约看到兵营的帐蓬。墙上挂着价格牌子(paizi)。靠窗的一张桌前，
一位青衣书生面前放了几大碗的水酒，却是不饮。
LONG );
	set("item_desc", ([
		"paizi" : "本店出售酱排骨及上等花雕酒。\n",
	]));
	set("exits", ([
		"down"    : __DIR__"songhe",
	]));
	set("objects", ([
			__DIR__"npc/jin" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -810);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}