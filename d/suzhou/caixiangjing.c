// Room: /d/suzhou/caixingjing.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
        set("short", "采香径");
        set("long",@long
这里名为采香径，又称“一箭径”，此溪乃吴王夫差陪西施游山之
必经之水道，也是越伐吴时，范蠡携西施，驾小舟出逃之处。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"shuiwa",
		"northwest" : __DIR__"shuiwa1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 900);
	set("coor/y", -1150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
