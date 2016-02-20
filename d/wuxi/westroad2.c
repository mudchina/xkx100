// Room: /d/wuxi/westroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "西新街");
	set("long", @LONG
西新街上的人虽然多得不得了，街面却还干净、整洁。人来人往，
吆喝声、叫卖声汇成一片。你看来川流不息的人群，心里异常兴奋和高
兴，街边的小贩吆喝着小笼馒头和鸡汤馄饨，令你食欲大开。南边的二
泉茶馆原本开在惠山下的真正的二泉旁边，后来为了生意还是搬到这条
街上来了，可每天都是派人专程去二泉用水车拉来泉水沏茶的。路北边
是这条街上生意最好的客栈，进出的都是来自天南地北的人。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"kedian",
		"south" : __DIR__"chaguan",
		"west"  : __DIR__"westgate",
		"east"  : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wulai" : 1,
	]));
	set("coor/x", 350);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}