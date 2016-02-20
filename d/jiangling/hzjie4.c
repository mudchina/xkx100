//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "汉正街");
	set ("long", @LONG
这是武汉最繁华的街道。从大江南北来的各色人等，熙熙攘攘，摩
肩接踵。东边是一家客栈，西边是卖药材的店铺，似乎有人在炮制中药，
传来一阵阵舂石臼的声音。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"kedian",
		"west" : __DIR__"yaocaidian",
		"south": __DIR__"hzjie5",
		"north": __DIR__"hzjie3",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
