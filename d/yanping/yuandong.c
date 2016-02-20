// Room: /d/yanping/yuandong.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "白猿洞");
	set("long", @LONG
白猿洞位于九峰深处，洞深百丈，入洞不辨五指。周围古树繁密，
遮天闭日，唯洞口凸出山崖处，老远就能看见。相传此洞附近曾有白猿
出没，风吹林响，便是与山下剑潭“龙津春浪”齐名的八景之一的“猿
洞秋风”了。
LONG );
	set("exits", ([
		"northwest" : __DIR__"shuyuan",
		"northeast" : __DIR__"xita",
	]));
	set("objects", ([
		__DIR__"npc/yuan" : 1,
	]));
	setup();
	replace_program(ROOM);
}
