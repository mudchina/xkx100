// Room: /d/huanggong/yangxin.c

inherit ROOM;

void create()
{
	set("short", "养心殿");
	set("long", @LONG
养心殿是皇帝居住和处理日常政务的地方. 在北墙上悬挂着一个匾
额(bian), 宝座屏风上有乾隆御笔题字(zi). 东暖阁竖着圣祖圣训和世
宗圣训各八条. 西暖阁里,  "勤政亲贤" 横幅下, 是一幅世宗的御笔楹
联(lian). 这是也一些官员在选拔, 调动前被带来见圣的地方. 书架上
存放着一些关于老皇帝治理国家的经验、教训的书籍, 是供小皇帝学习
的.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"yuehua",
	]));
	set("item_desc", ([ /* sizeof() == 2 */
		"bian"  : "
中正仁和\n\n",
		"zi"  : "
保泰常钦若
调元益懋哉\n\n",
		"lian"  : "
惟以一人治天下
岂为天下奉一人\n\n",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}