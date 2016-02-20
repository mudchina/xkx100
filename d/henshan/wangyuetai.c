// Room: /d/henshan/wangyuetai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "望月台");
        set("long", @LONG
望月台是祝融殿后一高耸巨石。每当夜籁，皓月当空，犹如玉盘冰
轮，漫洒万里清辉，清冷月色，辉映低昂的群峰。此时 "浩然万里，举
七十二峰，峰峰贮冰壶中，始信下方无此月也。" 前人因此有诗: 人间
朗魄已皆尽，此地清光犹未低。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"    : __DIR__"zhurongdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -980);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
