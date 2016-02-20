// Room: /d/wuxi/paotai.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "要塞炮台");
	set("long", @LONG
这已经来到了长江边了，官府在此修筑了江阴要塞炮台。四尊古铜
色的神威大炮巍然伫立，黑洞洞的炮口直对着江面。炮台上几名官兵来
回巡视，看见你，不耐烦地冲你一挥手，叫你赶快离开这儿。炮台下方
立着一个巨大的木牌(pai)，老远就能看见上面的字。
LONG );
	set("outdoors", "wuxi");
	set("item_desc", ([
		"pai" : "
※〈〉要塞方圆五十里江面，禁止打渔渡船！〈〉※\n",
	]));
	set("exits", ([
		"south"  : __DIR__"road6",
	]));
	set("objects", ([
		__DIR__"npc/junshi" : 4,
	]));
	set("coor/x", 370);
	set("coor/y", -720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}