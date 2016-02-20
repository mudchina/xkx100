// Room: /d/taishan/wangheting.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "望河亭");
	set("long", @LONG
玉皇庙西厢就是望河亭。黄河金带为泰山六大奇观之一。若新霁无
尘、夕阳西下时，举目北眺，在泰山西北层层峰峦的尽头，可看到黄河
象一条金色的带子闪闪发光，或河水反射到天空，形成蜃景，波光粼粼，
黄白相间，如同金银铺就一般，从西南至东北，一直伸向天地交界处。
恰如袁枚在《登泰山诗》中所描绘的：“一条黄水似衣带，穿破世间通
银河。” 
LONG );
	set("exits", ([
		"east" : __DIR__"yuhuang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
