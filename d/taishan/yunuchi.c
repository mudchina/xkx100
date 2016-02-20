// Room: /d/taishan/yunuchi.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "玉女池");
	set("long", @LONG
玉女池在碧霞祠西墙外，原为池，清代砌为井。传宋真宗东封泰山
时，在玉女池内发现玉女石像，易以玉像，建龛奉祭，封为“天仙玉女
碧霞元君”。从此香火大盛。
LONG );
	set("exits", ([
		"east"  : __DIR__"bixia",
		"north" : __DIR__"sibeiya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
