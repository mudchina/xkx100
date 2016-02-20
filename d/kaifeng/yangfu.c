// /kaifeng/yangfu.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "天波杨府");
	set("long", @LONG
天波杨府是抗辽名将杨业的府邸，自从杨业去世之后，府中只剩下
一些女子居住。门前的绿柳槐树旁，两块大石光滑异常，乃是当朝所赐。
文官过者下桥，武官过者下马。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"road3",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
