//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "锐金旗大院");
	set("long", @LONG
你走进了锐金旗的大院，却发现这里人影稀疏，虽听见叮叮咚咚的
打铁声，却见不到打铁铺，那声音似乎是从深远的地下传来的。向西走，
就要进入门楼了。院子左首可能是练武场，隐约传来打斗声；右首是一
座大厅，象是锐金旗的议会场所。
LONG );
	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
		"out": __DIR__"rjqmen",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}