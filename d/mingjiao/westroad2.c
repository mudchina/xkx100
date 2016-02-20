//westroad2.c

inherit ROOM;

void create()
{
	set("short", "深山");
	set("long", @TEXT
已经走了很久，山林越来越密，夜晚来临了，夜枭呼号，令人毛骨
悚然。真是“蜀道难，难于上青天”。再向西，就要出山了。突然，你
又发现南面有零星火光。
TEXT );
	set("outdoors", "mingjiao");
	set("exits",([
		"east" : __DIR__"westroad1",
		"west" : __DIR__"gebitan1",
		"south" : __DIR__"miaorenbuluo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}