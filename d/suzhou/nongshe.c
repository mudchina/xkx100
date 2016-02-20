// nongshe.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "农舍");
        set("long",@long
这是一间普通的农舍，里面陈设相当简陋，顶上的茅草也不整齐，
露出好几个天床。一位农夫正坐在门边抽旱烟。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"west" : __DIR__"caoebei",
	]));
	set("objects", ([
		__DIR__"npc/axiang" : 1,
	]));
	set("coor/x", 780);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
