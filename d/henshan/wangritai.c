// Room: /d/henshan/wangritai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "望日台");
        set("long", @LONG
望日台紧邻祝融殿。鸡鸣夜起，登台东望，遥见海门，云水皆赤，
倏忽异彩，日轮荡漾，若沉若浮，稍之奋涌而起，光耀夺目。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shiziyan",
           "northup"    : __DIR__"zhurongdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1000);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
