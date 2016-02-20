//Room: /d/dali/heisenlin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","黑森林");
	set("long",@LONG
迎面一大片黑压压的森林，高大的古松参天而立。左首一排
九株大松树，看起来有些特别。
LONG);
// 万劫谷 here.
// wait to be done in future.
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"dasenlin",
	]));
	set("no_clean_up", 0);
	set("coor/x", -35000);
	set("coor/y", -70100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}