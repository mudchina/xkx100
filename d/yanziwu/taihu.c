// Room: /d/yanziwu/taihua.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "太湖");
	set("long",@LONG
绿衫少女脸带微笑，如春花般娇痴无瑕。两手划桨，不时采摘莲实
戏耍。口中漫声唱道:  "菡萏香连十顷陂，小姑贪戏采莲迟。晚来弄水
船头滩，笑脱红裙裹鸭儿。" 碧玉般湖面淡淡弥散着轻柔的曲调。
LONG );
	set("outdoors", "yanziwu");
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
