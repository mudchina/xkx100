// cangjingge.c 雪山藏经室

inherit ROOM;

string* books = ({
        "/clone/book/mizong_book",
        "/clone/book/skin",
	"/clone/book/book-bamboo",
        "/clone/book/book-silk",
	"/clone/book/book-stone",
	"/clone/book/book-iron",
});
void create()
{
        set("short", "雪山藏经室");
	set("long", @LONG
这里是雪山寺的藏经室，靠墙是一排书架，摆满了各种拳谱、书籍。
大多是当年掌门人鸠摩智翻译的佛经和从少林寺取来的武学典籍。
LONG );
	set("exits", ([
                "southeast" : __DIR__"dating",
	]));

	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
                CLASS_D("xueshan")+"/daerba" : 1,
	]));
//        set("no_clean_up", 0);
	set("coor/x", -70010);
	set("coor/y", -19880);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
