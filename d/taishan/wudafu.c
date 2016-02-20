// Room: /d/taishan/wudafu.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "五大夫松");
	set("long", @LONG
《史记》载，秦始皇封泰山时中途遇雨，避于此间大树下，因封树
为“五大夫”。后讹为五株。明代万历年间，古松被雷雨所毁。清雍正
年间钦差丁皂保奉敕重修泰山时，补植五株松。古松拳曲古拙，苍劲葱
郁，自古被誉为“秦松挺秀”，列为泰安八景之一。
　　五大夫松西拦住山坡上有望人松，长枝下垂，似躬身招手邀客，又
名迎客松。
LONG );
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"eastdown"  : __DIR__"sandengya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 680);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
