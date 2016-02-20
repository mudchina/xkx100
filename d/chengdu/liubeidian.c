// Room: liubeidian.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "刘备殿");
	set("long", @LONG
这里是武侯祠的刘备殿。正中供着汉昭烈帝，高可丈许。后主却没得
供奉，所谓 "扶不起来" 的阿斗吧。而哭庙玉碎的北地王刘谌得能和英父
同祀，令人不胜唏嘘。
    殿下左右是赵云等的武将廊和蒋琬为首的文臣廊。
LONG );
	set("exits", ([
		"southdown" : __DIR__"wuhouci",
		"northup"   : __DIR__"zhugeliang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -3010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
