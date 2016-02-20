// buwei3.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", @LONG
这里是华山总所的后堂。梁间一块匾上写着“以气御剑”四个大字，
掌上布置肃穆，两壁悬着一柄柄长剑，剑鞘黝黑，剑穗陈旧，想是华山
派前代各宗师的佩剑，华山派今日在武林中这么大的声誉，不知道曾有
多少奸邪恶贼，丧生在这些前代宗师的长剑之下。正中神案的墙上是华
山派开山祖师风祖师的画象。画象神情清隽，非常传神。神案上香炉里
插着三柱清香，香烟袅袅上升，散发着一股檀香味。西面有扇门通往外
面的正厅。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"buwei1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("huashan")+"/first": 1,
	]));
	set("valid_startroom","1");

	set("coor/x", -850);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
	"/clone/board/huashan_b"->foo();
	replace_program(ROOM);
}
