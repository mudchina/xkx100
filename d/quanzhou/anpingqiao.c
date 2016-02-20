// Room: /d/quanzhou/wuliqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "安平桥");
	set("long", @LONG
这就是当代最长的海港大石桥“安平桥”，全桥长五里，宽丈五，
桥面上铺的都是大石板。石板有的长近十丈，重达五万斤，桥上有亭子
五座。中亭有历代重修碑记十三方，石雕武士两尊，亭柱上还有一幅对
联(duilian)。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"duilian" : "
           世间有佛尊斯佛
           天下无桥长此桥\n",
	]));
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 2 */
		"southup" : __DIR__"shanlu1",
		"north"   : "/d/fuzhou/puxian",
	]));
	set("no_clean_up", 0);

	set("coor/x", 1840);
	set("coor/y", -6360);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
