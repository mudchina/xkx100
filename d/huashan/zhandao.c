// zhandao.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "长空栈道");
	set("long", @LONG
栈道以铁斜插，上覆青石板，宽不足八寸。上乃绝壁，下亦绝壁。
挽索登其上，只听山风呼啸，林涛怒吼。远处偶传一两声禽鸣兽嘶，更
使人毛骨悚然。踏上悬空的栈道，紧攀铁索，屏息静气，缓步挪动，才
能过去。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"luoyan",
		"northdown" : __DIR__"sgyhole",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -860);
	set("coor/y", 130);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
