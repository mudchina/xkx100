// /kaifeng/jiaowai.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create ()
{
	set ("short","郊外");
	set ("long", @LONG
此处是开封北郊，由于离开封很近，治安相对稳定，由此去嵩山进
香的客人络绎不绝，一幅太平景象。
LONG);
	set("outdoors", "kaifeng");
	set("exits", ([
		"south" : __DIR__"xuandemen",
		"westup" : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
