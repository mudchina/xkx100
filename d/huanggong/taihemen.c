// Room: /d/huanggong/taihemen.c

inherit ROOM;

void create()
{
	set("short", "太和门");
	set("long", @LONG
这是三大殿的前门. 门前立着一对铜铸狮子, 东边是只雄狮前足踏
绣球, 象征权力和统一寰宇. 西边是只雌狮, 前肢抚弄一小乳狮, 象征
子嗣昌盛.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"wumen",
		"north" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}