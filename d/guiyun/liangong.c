// Room: /guiyun/liangong.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是归云庄陆少庄主的练功房。由于陆少庄主乃少林旁支仙霞派
出身，所以房中布置尽是为习练外门硬功之用，竖立着不少木桩和草靶。
西边角上还有两个大沙坑，天花板上吊着一只大沙袋。
LONG );
	set("exits", ([
		"west"  : __DIR__"zoulang4",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 3,
	]));
	setup();
	replace_program(ROOM);
}
