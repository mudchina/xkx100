// Room: /d/wuyi/taoyuan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "桃花源");
	set("long", @LONG
过了石门，豁然开朗，“到此已非尘世客，过来便是桃源人”。只
见四周群峦环绕，田畴平旷，阡陌纵横，屋舍俨然，桃花盛开，灿若云
霞。屋舍边翠竹丛丛，袅娜摇曳，引人入胜。宋代陈石堂、吴正理皆在
此避世隐居。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"taoyuandong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

