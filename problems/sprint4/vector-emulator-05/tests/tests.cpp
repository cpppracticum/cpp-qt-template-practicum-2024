
// Core headers
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLabel>

#include <QtTest>

#include <vector>
#include <string>

#include "mainwindow.h"

#include "utils.h"


class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:
    void init();
    void cleanup();

    void TestPushBack();
    void TestPopBack();
    void TestClear();

    void TestDays();
    void TestMonths();

    void TestEdit();
    void TestDec();
    void TestInc();
    void TestBegin();
    void TestEnd();

    void TestInsert();
    void TestErase();

    void TestIteratorInvalidation();

    void TestReserve();
    void TestResizeUp();
    void TestResizeDown();

    void TestFind();
    void TestCount();

    void TestMinElement();
    void TestMaxElement();

    void TestSort();
    void TestsOrT();
    void TestShuffle();
    void TestUnique();
    void TestUniqueUnsorted();
    void TestReverse();


private:
    [[nodiscard]] std::vector<QString> getVector() const;
    [[nodiscard]] int getIndex() const;
    void checkExpectedVector() const;
    void checkIndex() const;
    void checkEnd() const;
    void checkButtons() const;
    void checkContent() const;
    void checkCapacity() const;
    void checkSize() const;

    void checkModel() const;

    void pushBack(const QString& str);
    void pushBackVector(const std::vector<QString>& vector);
    void popBack();
    void clear();

    void insert();
    void insert(const QString& str);
    void erase();

    void begin();
    void end();
    void inc();
    void dec();

    void edit();
    void edit(const QString& str);

    void reserve() const;
    void reserve(size_t new_capacity);
    void resize() const;
    void resize(size_t new_size);

    void find(const QString& str);

    [[nodiscard]] size_t count(const QString& str) const;

    void min_element();
    void max_element();

    void sort();
    void sOrT();
    void shuffle();
    void shuffle(size_t seed);
    void unique();
    void reverse();

    void setCurrentElement(int index);

    MainWindow *window;

    QListWidget *list_widget{};
    QLineEdit *txt_elem_content{};
    QLineEdit *txt_size{};
    QLineEdit *txt_capacity{};
    QLineEdit *le_count{};

    QLabel *lbl_count{};

    QPushButton *btn_push_back{};
    QPushButton *btn_pop_back{};
    QPushButton *btn_clear{};
    QPushButton *btn_days{};
    QPushButton *btn_months{};

    QPushButton *btn_erase;
    QPushButton *btn_insert;

    QPushButton *btn_begin;
    QPushButton *btn_end;
    QPushButton *btn_inc;
    QPushButton *btn_dec;

    QPushButton *btn_edit;

    QPushButton *btn_reserve;
    QPushButton *btn_resize;

    QPushButton *btn_find;
    QPushButton *btn_count;

    QPushButton *btn_min_element;
    QPushButton *btn_max_element;

    QPushButton *btn_sort;
    QPushButton *btn_sOrT;
    QPushButton *btn_shuffle;
    QPushButton *btn_unique;
    QPushButton *btn_reverse;

    using container = std::vector<QString>;
    container vec{};
    container::iterator it = vec.begin();
    QString content;

    std::mt19937 random_gen;

    static inline const std::vector<QString> days_of_week = {
        "Понедельник",
        "Вторник",
        "Среда",
        "Четверг",
        "Пятница",
        "Суббота",
        "Воскресенье"
    };

    static inline const std::vector<QString> months_of_year = {
        "Январь",
        "Февраль",
        "Март",
        "Апрель",
        "Май",
        "Июнь",
        "Июль",
        "Август",
        "Сентябрь",
        "Октябрь",
        "Ноябрь",
        "Декабрь"
    };


    static inline const container default_lines{
        "first row",
        "second row",
        "third row",
        "fourth row",
        "fifth row"
    };

};



void TestYourApp::init()
{
    window = new MainWindow();

    QVERIFY2(window != nullptr, "Главное окно не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Главное окно не активируется");
    list_widget = getChild<QListWidget>(window, "list_widget", "QListWidget");
    txt_elem_content = getChild<QLineEdit>(window, "txt_elem_content", "QLineEdit");
    txt_size = getChild<QLineEdit>(window, "txt_size", "QLineEdit");
    txt_capacity = getChild<QLineEdit>(window, "txt_capacity", "QLineEdit");
    le_count = getChild<QLineEdit>(window, "le_count", "QLineEdit");

    lbl_count = getChild<QLabel>(window, "lbl_count", "QLabel");

    btn_push_back = getChildByText<QPushButton>(window, "push_back", "QPushButton");
    btn_pop_back = getChildByText<QPushButton>(window, "pop_back", "QPushButton");
    btn_clear = getChildByText<QPushButton>(window, "clear", "QPushButton");
    btn_days = getChildByText<QPushButton>(window, "= дни недели", "QPushButton");
    btn_months = getChildByText<QPushButton>(window, "= месяцы", "QPushButton");

    btn_erase = getChildByText<QPushButton>(window, "erase", "QPushButton");
    btn_insert = getChildByText<QPushButton>(window, "insert", "QPushButton");

    btn_begin = getChildByText<QPushButton>(window, "begin", "QPushButton");
    btn_end = getChildByText<QPushButton>(window, "end", "QPushButton");
    btn_inc = getChildByText<QPushButton>(window, "++", "QPushButton");
    btn_dec = getChildByText<QPushButton>(window, "--", "QPushButton");

    btn_edit = getChildByText<QPushButton>(window, "Edit", "QPushButton");

    btn_reserve = getChildByText<QPushButton>(window, "reserve", "QPushButton");
    btn_resize = getChildByText<QPushButton>(window, "resize", "QPushButton");

    btn_find = getChildByText<QPushButton>(window, "find", "QPushButton");
    btn_count = getChildByText<QPushButton>(window, "count", "QPushButton");

    btn_min_element = getChildByText<QPushButton>(window, "min_element", "QPushButton");
    btn_max_element = getChildByText<QPushButton>(window, "max_element", "QPushButton");

    btn_sort = getChildByText<QPushButton>(window, "sort", "QPushButton");
    btn_sOrT = getChildByText<QPushButton>(window, "sOrT", "QPushButton");
    btn_shuffle = getChildByText<QPushButton>(window, "shuffle", "QPushButton");
    btn_unique = getChildByText<QPushButton>(window, "unique", "QPushButton");
    btn_reverse = getChildByText<QPushButton>(window, "reverse", "QPushButton");


    vec = {};
    it = vec.begin();
    content = {};
    vec.shrink_to_fit();

    random_gen.seed(12);
}

std::vector<QString> TestYourApp::getVector() const {
    std::vector<QString> lines;
    const auto size = list_widget->count();
    lines.reserve(size);
    for (int i = 0; i < size - 1; ++i) {
        const auto& item = list_widget->item(i);
        lines.push_back(item->text());
    }
    return lines;
}

int TestYourApp::getIndex() const {
    return list_widget->currentRow();
}

void TestYourApp::checkExpectedVector() const {
    const auto actual_vector = getVector();

    QVERIFY2(vec.size() == actual_vector.size(), "Размер вектора не совпадает с ожидаемым");
    const auto size_from_string = txt_size->text().toUInt();
    QVERIFY2(actual_vector.size() == size_from_string, "Размер в поле txt_size не совпадает с реальным");
    for (size_t i = 0; i < vec.size(); ++i) {
        const QString expected_string = QString("%1: %2").arg(i).arg(vec.at(i));
        const auto& actual_string = actual_vector.at(i);
        QVERIFY2(expected_string == actual_string, "Строка вектора не совпадает с ожидаемой");
    }
}

void TestYourApp::checkIndex() const {
    const auto actual = getIndex();
    const auto expected = it - vec.begin();
    QVERIFY2(actual == expected, "Индекс выбранного элемента не совпадает с ожидаемым");
}

void TestYourApp::checkEnd() const {
    const auto size = list_widget->count();
    QVERIFY2(size, "В векторе отстствуют элементы, в том числе фиктивный элемент end");
    const auto *const end_element = list_widget->item(size - 1);
    QVERIFY2(end_element->text() == "end", "Последний элемент вектора всегда должен быть end");
}

void TestYourApp::checkButtons() const {
    // Можно проверять по внутреннему итератору,
    // поскольку уже выполнены проверки совпадения векторов и итераторов
    const auto should_be_enabled = it != vec.end();

    QVERIFY2(btn_edit->isEnabled() == should_be_enabled, "Кнопка Edit должна быть неактивна, когда итератор указывает на фиктивный элемент end, и активна в иных случаях");
    QVERIFY2(btn_inc->isEnabled() == should_be_enabled, "Кнопка ++ должна быть неактивна, когда итератор указывает на фиктивный элемент end, и активна в иных случаях");
    QVERIFY2(btn_erase->isEnabled() == should_be_enabled, "Кнопка erase должна быть неактивна, когда итератор указывает на фиктивный элемент end, и активна в иных случаях");

    const auto is_it_begin = it == vec.begin();
    QVERIFY2(btn_dec->isEnabled() != is_it_begin, "Кнопка -- должна быть неактивна, когда итератор указывает на начало вектора, и активна в иных случаях");
}

void TestYourApp::checkContent() const {
    // Аналогично checkButtons, можно проверять по внутреннему итератору,
    // поскольку уже выполнены проверки совпадения векторов и итераторов
    const auto& actual_text = txt_elem_content->text();
    if (it == vec.end()) {
        QVERIFY2(actual_text == "", "Текст в txt_elem_content должен отсутствовать, если итератор указывает на конец массива");
        return;
    };
    const auto& expected_text = *it;
    QVERIFY2(actual_text == expected_text, "Текст в txt_elem_content не совпадает с ожидаемым");
}

void TestYourApp::checkCapacity() const {
    const auto capacity_str = txt_capacity->text();
    const size_t capacity = capacity_str.toUInt();
    const size_t expected_capacity = vec.capacity();
    QVERIFY2(capacity >= expected_capacity, "Вместимость вектора меньше ожидаемой");
}

void TestYourApp::checkSize() const {
    const auto size_str = txt_size->text();
    const size_t size = size_str.toUInt();
    const size_t expected_size = vec.size();
    QVERIFY2(size == expected_size, "Размер вектора в txt_size не совпадает с ожидаемым");
}

void TestYourApp::checkModel() const {
    checkEnd();
    checkExpectedVector();
    checkIndex();
    checkButtons();
    checkContent();
    checkCapacity();
    checkSize();
}

void TestYourApp::pushBack(const QString& str) {
    txt_elem_content->setText(str);
    clickWidget(btn_push_back);

    vec.push_back(str);
    it = vec.begin();
}

void TestYourApp::pushBackVector(const std::vector<QString>& vector) {
    for (const auto& item : vector) {
        pushBack(item);
    }
}

void TestYourApp::popBack() {
    clickWidget(btn_pop_back);
    vec.pop_back();
    it = vec.begin();
}

void TestYourApp::clear() {
    clickWidget(btn_clear);
    vec.clear();
    it = vec.begin();
}

void TestYourApp::insert() {
    clickWidget(btn_insert);
    vec.insert(it, content);
    it = vec.begin();
}

void TestYourApp::insert(const QString& str) {
    txt_elem_content->setText(str);
    content = str;
    insert();
}

void TestYourApp::erase() {
    clickWidget(btn_erase);
    vec.erase(it);
    it = vec.begin();
}

void TestYourApp::begin() {
    clickWidget(btn_begin);
    it = vec.begin();
}

void TestYourApp::end() {
    clickWidget(btn_end);
    it = vec.end();
}

void TestYourApp::inc() {
    clickWidget(btn_inc);
    ++it;
}

void TestYourApp::dec() {
    clickWidget(btn_dec);
    --it;
}

void TestYourApp::edit() {
    clickWidget(btn_edit);
    *it = content;
}

void TestYourApp::edit(const QString& str) {
    txt_elem_content->setText(str);
    content = str;
    edit();
}

void TestYourApp::reserve() const {
    clickWidget(btn_reserve);
}

void TestYourApp::reserve(const size_t new_capacity) {
    txt_capacity->setText(QString::number(new_capacity));
    reserve();

    vec.reserve(new_capacity);
    it = vec.begin();
}

void TestYourApp::resize() const {
    clickWidget(btn_resize);
}

void TestYourApp::resize(const size_t new_size) {
    txt_size->setText(QString::number(new_size));
    resize();

    vec.resize(new_size);
    it = vec.begin();
}

void TestYourApp::find(const QString& str) {
    txt_elem_content->setText(str);
    clickWidget(btn_find);
    it = std::find(vec.begin(), vec.end(), str);
}

size_t TestYourApp::count(const QString& str) const {
    le_count->setText(str);
    clickWidget(btn_count);
    const auto count_str = lbl_count->text();
    return count_str.toUInt();
}

void TestYourApp::min_element() {
    clickWidget(btn_min_element);
    it = std::min_element(vec.begin(), vec.end());
}

void TestYourApp::max_element() {
    clickWidget(btn_max_element);
    it = std::max_element(vec.begin(), vec.end());
}

void TestYourApp::sort() {
    clickWidget(btn_sort);
    std::sort(vec.begin(), vec.end());
}

void TestYourApp::sOrT() {
    clickWidget(btn_sOrT);
    std::sort(vec.begin(), vec.end(), [](const QString& left, const QString& right) { return QString::compare(left, right, Qt::CaseInsensitive) < 0;});
}

void TestYourApp::shuffle() {
    window->SetRandomGen(random_gen);
    clickWidget(btn_shuffle);
    std::shuffle(vec.begin(), vec.end(), random_gen);
}

void TestYourApp::shuffle(size_t seed) {
    random_gen.seed(seed);
    shuffle();
}

void TestYourApp::unique() {
    clickWidget(btn_unique);

    if (!std::is_sorted(vec.begin(), vec.end())) {
        return;
    }
    const auto to_del = std::unique(vec.begin(), vec.end());
    vec.erase(to_del, vec.end());
    it = vec.begin();
}

void TestYourApp::reverse() {
    clickWidget(btn_reverse);
    std::reverse(vec.begin(), vec.end());
}

void TestYourApp::setCurrentElement(int index) {
    // С разрешением указывать на end
    const int clamped_index = std::clamp(index, 0, static_cast<int>(vec.size()));
    it = vec.begin() + clamped_index;
    list_widget->setCurrentRow(clamped_index);
}

void TestYourApp::TestPushBack() {
    const std::vector<QString> lines{
        "first row",
        "second row"
    };
    pushBackVector(lines);
    checkModel();
}

void TestYourApp::TestPopBack() {
    QVERIFY2(getVector().empty(), "Вектор объектов должен быть пустым при старте программы");
    QVERIFY2(!btn_pop_back->isEnabled(), "Кнопка pop_back должна быть выключена для пустого вектора");

    std::vector<QString> lines{
        "first row",
        "second row",
        "third row"
    };
    pushBackVector(lines);
    checkModel();
    while(!vec.empty()) {
        popBack();
    }
    checkModel();
    QVERIFY2(!btn_pop_back->isEnabled(), "Кнопка pop_back должна быть выключена для пустого вектора");
}

void TestYourApp::TestClear() {
    std::vector<QString> lines{
        "first row",
        "second row",
        "third row"
    };

    pushBackVector(lines);
    checkModel();

    lines.clear();
    clear();
    checkModel();
}

void TestYourApp::TestDays() {
    clickWidget(btn_days);
    vec = days_of_week;
    it = vec.begin();
    checkModel();
}

void TestYourApp::TestMonths() {
    clickWidget(btn_months);
    vec = months_of_year;
    it = vec.begin();
    checkModel();
}


void TestYourApp::TestEdit() {
    pushBackVector(default_lines);

    checkModel();
    edit("new first row");

    setCurrentElement(2);
    edit("new third row");
    checkModel();

    setCurrentElement(3);
    edit("new fourth row");
    checkModel();
}

void TestYourApp::TestBegin() {
    pushBackVector(default_lines);

    setCurrentElement(3);
    checkModel();
    begin();
    checkModel();

    setCurrentElement(2);
    begin();
    checkModel();
}

void TestYourApp::TestEnd() {
    pushBackVector(default_lines);

    end();
    checkModel();
    setCurrentElement(3);
    end();
    checkModel();
}

void TestYourApp::TestDec() {
    pushBackVector(default_lines);
    end();
    while(it != vec.end()) {
        dec();
        checkModel();
    }
}

void TestYourApp::TestInc() {
    pushBackVector(default_lines);
    begin();
    while(it != vec.end()) {
        inc();
        checkModel();
    }
}

void TestYourApp::TestErase() {
    pushBackVector(default_lines);
    setCurrentElement(2);
    erase();
    checkModel();
    setCurrentElement(static_cast<int>(vec.size()) - 1);
    erase();
    checkModel();
}

void TestYourApp::TestInsert() {
    pushBackVector(default_lines);
    setCurrentElement(3);
    insert("New string");
    checkModel();
    setCurrentElement(3);
    insert("New new string");
    checkModel();

    setCurrentElement(static_cast<int>(vec.size()));
    insert("New string at the end");
    checkModel();
}


void TestYourApp::TestIteratorInvalidation() {
    pushBackVector(default_lines);

    setCurrentElement(3);
    pushBack("New string at the back");
    checkModel();

    setCurrentElement(5);
    popBack();
    checkModel();

    setCurrentElement(1);
    insert("Inserted string");
    checkModel();

    setCurrentElement(2);
    erase();
    checkModel();

    setCurrentElement(4);
    clear();
    checkModel();
}


void TestYourApp::TestReserve() {
    pushBackVector(default_lines);
    reserve(25);
    checkModel();

    pushBackVector(default_lines);
    checkModel();
}

void TestYourApp::TestResizeUp() {
    pushBackVector(default_lines);
    checkModel();
    resize(default_lines.size() + 15);
    checkModel();
    setCurrentElement(static_cast<int>(default_lines.size() + 3));
    edit("New string");
    checkModel();
}

void TestYourApp::TestResizeDown() {
    pushBackVector(default_lines);
    pushBackVector(default_lines);
    checkModel();
    resize(default_lines.size() + 1);
    checkModel();
    setCurrentElement(static_cast<int>(default_lines.size() - 1));
    edit("New string");
    checkModel();
}

void TestYourApp::TestFind() {
    pushBackVector(default_lines);
    const QString& string_to_find = default_lines.at(3);
    find(string_to_find);
    checkModel();

    const QString string_to_not_find = "That line is not from there, at least it should not be";
    find(string_to_not_find);
    checkModel();
}

void TestYourApp::TestCount() {
    const container lines = {
        "First unique line",
        "Not so unique line!",
        "Not so unique line!",
        "Not so unique line!",
        "Not so unique line!",
        "Not so unique line!",
        "Second totally unique line",
        "That line is also not actually unique",
        "That line is also not actually unique",
        "That line is also not actually unique",
        "Last unique line",
        "Just kidding, this is the last one ;)"
    };
    pushBackVector(lines);
    checkModel();
    const auto first_non_unique_line_quantity = count(lines.at(1));
    QVERIFY2(first_non_unique_line_quantity == 5, "Количество вхождений строки не совпадает с ожидаемым");

    const auto second_non_unique_line_quantity = count(lines.at(7));
    QVERIFY2(second_non_unique_line_quantity == 3, "Количество вхождений строки не совпадает с ожидаемым");

    for (const auto& line : {lines[0], lines[6], lines[10], lines[11]}) {
        QVERIFY2(count(line) == 1, "Количество вхождений уникальной строки не совпадает с ожидаемым");
    }

    QVERIFY2(count("Line is not from vector") == 0, "Количество вхождений строки, отсутствующей в векторе, отлично от нуля");
}

void TestYourApp::TestMinElement() {
    const container lines = {
        "AAA",
        "bbb",
        "ddd",
        "Some normal line",
    };
    pushBackVector(lines);
    checkModel();
    min_element();
    checkModel();

    pushBack("0 as the lowest number here, will it be the lowest character?");
    checkModel();
    min_element();
    checkModel();

    pushBack("a normal line starting with letter a");
    checkModel();
    min_element();
    checkModel();
}

void TestYourApp::TestMaxElement() {
    const container lines = {
        "AAA",
        "bbb",
        "ddd",
        "Some normal line",
    };
    pushBackVector(lines);
    checkModel();
    max_element();
    checkModel();

    pushBack("9 as the highest number here, will it be the highest character?");
    checkModel();
    max_element();
    checkModel();

    pushBack("You are going to be a great programmer, aren't you?");
    checkModel();
    max_element();
    checkModel();
}


void TestYourApp::TestSort() {
    const container lines = {
        "BBB",
        "AAbA",
        "bbA",
        "a",
        "ddD",
        "DAA"
        };
    pushBackVector(lines);
    setCurrentElement(3);
    checkModel();
    sort();
    checkModel();
}


void TestYourApp::TestsOrT() {
    const container lines = {
        "BBB",
        "AAbA",
        "bbA",
        "a",
        "ddD",
        "DAA"
        };
    pushBackVector(lines);
    setCurrentElement(1);
    checkModel();
    sOrT();
    checkModel();
}

void TestYourApp::TestShuffle() {
    const container lines = {
        "BBB",
        "AAbA",
        "bbA",
        "a",
        "ddD",
        "DAA"
        };
    pushBackVector(lines);
    setCurrentElement(5);
    checkModel();
    shuffle(157);
    checkModel();
    shuffle(574);
    checkModel();
}

void TestYourApp::TestUnique() {
    const container lines = {
        "BBB",
        "AAbA",
        "bbA",
        "BBB",
        "a",
        "ddD",
        "a",
        "a",
        "AAD",
        "BBB",
        "DAA"
        };
    pushBackVector(lines);
    setCurrentElement(7);
    checkModel();
    sort();
    checkModel();
    unique();
    checkModel();
}

void TestYourApp::TestUniqueUnsorted() {
    const container lines = {
        "BBB",
        "AAbA",
        "bbA",
        "BBB",
        "a",
        "ddD",
        "a",
        "a",
        "AAD",
        "BBB",
        "DAA"
        };
    pushBackVector(lines);
    setCurrentElement(6);
    checkModel();
    unique();
    checkModel();
}

void TestYourApp::TestReverse() {
    const container lines = {
        "BBB",
        "AAbA",
        "bbA",
        "BBB",
        "a",
        "ddD",
        "a",
        "a",
        "AAD",
        "BBB",
        "DAA"
        };
    pushBackVector(lines);
    setCurrentElement(2);

    checkModel();
    reverse();
    checkModel();
    sort();
    checkModel();
    reverse();
    checkModel();
}

void TestYourApp::cleanup()
{
    delete window;
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"