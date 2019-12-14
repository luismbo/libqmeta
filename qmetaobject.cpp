#include <QMetaObject>
#include <QMetaMethod>
#include <QMetaProperty>
#include <QMetaType>
#include <QObject>

// Widgets
#include <QApplication>
#include <QGuiApplication>
#include <QCoreApplication>
#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QCommandLinkButton>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QTimeEdit>
#include <QDial>
#include <QFocusFrame>
#include <QFontComboBox>
#include <QLabel>
#include <QLCDNumber>
#include <QLineEdit>
#include <QMenu>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSizeGrip>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QTabBar>
#include <QTabWidget>
#include <QToolBox>
#include <QToolButton>
#include <QColumnView>
#include <QDataWidgetMapper>
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QUndoView>
#include <QCalendarWidget>
#ifdef Q_OS_MACOS
#include <QMacCocoaViewContainer>
#include <QMacNativeWidget>
#endif
#include <QAbstractButton>
#include <QAbstractScrollArea>
#include <QAbstractSlider>
#include <QAbstractSpinBox>
#include <QFrame>
#include <QDialog>
#include <QButtonGroup>
#include <QGroupBox>
#include <QSplitter>
#include <QSplitterHandle>
#include <QStackedWidget>
#include <QTabWidget>
#include <QGraphicsEffect>
#include <QGraphicsAnchor>
#include <QGraphicsAnchorLayout>
#include <QGraphicsGridLayout>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsObject>
#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsLayout>
#include <QGraphicsLayoutItem>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneHelpEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>
#include <QGraphicsSceneResizeEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsTransform>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QStyleOptionGraphicsItem>
#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QPersistentModelIndex>
#include <QAbstractProxyModel>
//#include <QConcatenateTablesProxyModel> // 5.13
#include <QIdentityProxyModel>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QItemSelectionRange>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QAbstractItemDelegate>
#include <QAbstractItemView>
#include <QColumnView>
#include <QDataWidgetMapper>
#include <QHeaderView>
#include <QItemDelegate>
#include <QItemEditorCreator>
#include <QItemEditorCreatorBase>
#include <QItemEditorFactory>
#include <QStandardItemEditorCreator>
#include <QListView>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStyledItemDelegate>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTableWidgetSelectionRange>
#include <QTreeView>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include <QFileSystemModel>
#include <QAction>
#include <QActionGroup>
#include <QWidgetAction>
#include <QDockWidget>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QSizeGrip>
#include <QStatusBar>
#include <QToolBar>
#include <QCursor>
#include <QPalette>
#include <QColor>
//#include <QColorSpace> // 5.14
//#include <QColorTransform> // 5.14
#include <QFont>
#include <QFontDatabase>
#include <QFontInfo>
#include <QGraphicsAnchor>
#include <QGraphicsAnchorLayout>
#include <QCommonStyle>
#include <QStyle>
#include <QStyleFactory>
#include <QStyleHintReturn>
#include <QStyleHintReturnMask>
#include <QStyleHintReturnVariant>
#include <QStyleOption>
#include <QStylePainter>
#include <QGraphicsAnchor>
#include <QGraphicsAnchorLayout>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QLayout>
#include <QLayoutItem>
#include <QSpacerItem>
#include <QWidgetItem>
#include <QSizePolicy>
#include <QStackedLayout>
#include <QButtonGroup>
#include <QGroupBox>
#include <QStackedWidget>

// SVG
//#include <QGraphicsSvgItem>

#include "qmetaobject.h"

/*
 * Register metatypes for Qt class.
 *
 * This essentially lets us use the QMetaType API to look up meta objects by
 * class name.
 */

Q_DECLARE_METATYPE(QApplication*)
Q_DECLARE_METATYPE(QGuiApplication*)
Q_DECLARE_METATYPE(QCoreApplication*)
// Q_DECLARE_METATYPE(QObject*) // predefined
Q_DECLARE_METATYPE(QWidget*)
Q_DECLARE_METATYPE(QCheckBox*)
Q_DECLARE_METATYPE(QComboBox*)
Q_DECLARE_METATYPE(QCommandLinkButton*)
Q_DECLARE_METATYPE(QDateEdit*)
Q_DECLARE_METATYPE(QDateTimeEdit*)
Q_DECLARE_METATYPE(QTimeEdit*)
Q_DECLARE_METATYPE(QDial*)
Q_DECLARE_METATYPE(QFocusFrame*)
Q_DECLARE_METATYPE(QFontComboBox*)
Q_DECLARE_METATYPE(QLabel*)
Q_DECLARE_METATYPE(QLCDNumber*)
Q_DECLARE_METATYPE(QLineEdit*)
Q_DECLARE_METATYPE(QMenu*)
Q_DECLARE_METATYPE(QProgressBar*)
Q_DECLARE_METATYPE(QPushButton*)
Q_DECLARE_METATYPE(QRadioButton*)
Q_DECLARE_METATYPE(QScrollArea*)
Q_DECLARE_METATYPE(QScrollBar*)
Q_DECLARE_METATYPE(QSizeGrip*)
Q_DECLARE_METATYPE(QSlider*)
Q_DECLARE_METATYPE(QDoubleSpinBox*)
Q_DECLARE_METATYPE(QSpinBox*)
Q_DECLARE_METATYPE(QTabBar*)
Q_DECLARE_METATYPE(QTabWidget*)
Q_DECLARE_METATYPE(QToolBox*)
Q_DECLARE_METATYPE(QToolButton*)
Q_DECLARE_METATYPE(QColumnView*)
Q_DECLARE_METATYPE(QDataWidgetMapper*)
Q_DECLARE_METATYPE(QListView*)
Q_DECLARE_METATYPE(QTableView*)
Q_DECLARE_METATYPE(QTreeView*)
Q_DECLARE_METATYPE(QUndoView*)
Q_DECLARE_METATYPE(QCalendarWidget*)
#ifdef Q_OS_MACOS
Q_DECLARE_METATYPE(QMacCocoaViewContainer*)
Q_DECLARE_METATYPE(QMacNativeWidget*)
#endif
Q_DECLARE_METATYPE(QAbstractButton*)
Q_DECLARE_METATYPE(QAbstractScrollArea*)
Q_DECLARE_METATYPE(QAbstractSlider*)
Q_DECLARE_METATYPE(QAbstractSpinBox*)
Q_DECLARE_METATYPE(QFrame*)
Q_DECLARE_METATYPE(QDialog*)
Q_DECLARE_METATYPE(QButtonGroup*)
Q_DECLARE_METATYPE(QGroupBox*)
Q_DECLARE_METATYPE(QSplitter*)
Q_DECLARE_METATYPE(QSplitterHandle*)
Q_DECLARE_METATYPE(QStackedWidget*)
//Q_DECLARE_METATYPE(QTabWidget*) // predefined
Q_DECLARE_METATYPE(QGraphicsEffect*)
Q_DECLARE_METATYPE(QGraphicsAnchor*)
Q_DECLARE_METATYPE(QGraphicsAnchorLayout*)
Q_DECLARE_METATYPE(QGraphicsGridLayout*)
Q_DECLARE_METATYPE(QAbstractGraphicsShapeItem*)
Q_DECLARE_METATYPE(QGraphicsEllipseItem*)
//Q_DECLARE_METATYPE(QGraphicsItem*) // predefined
Q_DECLARE_METATYPE(QGraphicsItemGroup*)
Q_DECLARE_METATYPE(QGraphicsLineItem*)
Q_DECLARE_METATYPE(QGraphicsObject*)
Q_DECLARE_METATYPE(QGraphicsPathItem*)
Q_DECLARE_METATYPE(QGraphicsPixmapItem*)
Q_DECLARE_METATYPE(QGraphicsPolygonItem*)
Q_DECLARE_METATYPE(QGraphicsRectItem*)
Q_DECLARE_METATYPE(QGraphicsSimpleTextItem*)
Q_DECLARE_METATYPE(QGraphicsTextItem*)
Q_DECLARE_METATYPE(QGraphicsLayout*)
Q_DECLARE_METATYPE(QGraphicsLayoutItem*)
Q_DECLARE_METATYPE(QGraphicsLinearLayout*)
Q_DECLARE_METATYPE(QGraphicsProxyWidget*)
Q_DECLARE_METATYPE(QGraphicsScene*)
Q_DECLARE_METATYPE(QGraphicsSceneContextMenuEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneDragDropEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneHelpEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneHoverEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneMouseEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneMoveEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneResizeEvent*)
Q_DECLARE_METATYPE(QGraphicsSceneWheelEvent*)
Q_DECLARE_METATYPE(QGraphicsTransform*)
Q_DECLARE_METATYPE(QGraphicsView*)
Q_DECLARE_METATYPE(QGraphicsWidget*)
Q_DECLARE_METATYPE(QStyleOptionGraphicsItem*)
// Q_DECLARE_METATYPE(QGraphicsSvgItem*) // svg
Q_DECLARE_METATYPE(QAbstractItemModel*)
Q_DECLARE_METATYPE(QAbstractListModel*)
Q_DECLARE_METATYPE(QAbstractTableModel*)
Q_DECLARE_METATYPE(QModelIndex*)
Q_DECLARE_METATYPE(QPersistentModelIndex*)
Q_DECLARE_METATYPE(QAbstractProxyModel*)
// Q_DECLARE_METATYPE(QConcatenateTablesProxyModel*) // Qt 5.13
Q_DECLARE_METATYPE(QIdentityProxyModel*)
Q_DECLARE_METATYPE(QItemSelection*)
Q_DECLARE_METATYPE(QItemSelectionModel*)
Q_DECLARE_METATYPE(QItemSelectionRange*)
Q_DECLARE_METATYPE(QSortFilterProxyModel*)
Q_DECLARE_METATYPE(QStringListModel*)
Q_DECLARE_METATYPE(QStandardItem*)
Q_DECLARE_METATYPE(QStandardItemModel*)
Q_DECLARE_METATYPE(QAbstractItemDelegate*)
Q_DECLARE_METATYPE(QAbstractItemView*)
// Q_DECLARE_METATYPE(QColumnView*) // predefined
// Q_DECLARE_METATYPE(QDataWidgetMapper*) // predefined
Q_DECLARE_METATYPE(QHeaderView*)
Q_DECLARE_METATYPE(QItemDelegate*)
// Q_DECLARE_METATYPE(QItemEditorCreator*) // requires template arguments
Q_DECLARE_METATYPE(QItemEditorCreatorBase*)
Q_DECLARE_METATYPE(QItemEditorFactory*)
// Q_DECLARE_METATYPE(QStandardItemEditorCreator*) // requires template arguments
// Q_DECLARE_METATYPE(QListView*) // predefined
Q_DECLARE_METATYPE(QListWidget*)
Q_DECLARE_METATYPE(QListWidgetItem*)
Q_DECLARE_METATYPE(QStyledItemDelegate*)
// Q_DECLARE_METATYPE(QTableView*) // predefined
Q_DECLARE_METATYPE(QTableWidget*)
Q_DECLARE_METATYPE(QTableWidgetItem*)
Q_DECLARE_METATYPE(QTableWidgetSelectionRange*)
// Q_DECLARE_METATYPE(QTreeView*) // predefined
Q_DECLARE_METATYPE(QTreeWidget*)
Q_DECLARE_METATYPE(QTreeWidgetItem*)
Q_DECLARE_METATYPE(QTreeWidgetItemIterator*)
Q_DECLARE_METATYPE(QFileSystemModel*)
Q_DECLARE_METATYPE(QAction*)
Q_DECLARE_METATYPE(QActionGroup*)
Q_DECLARE_METATYPE(QWidgetAction*)
Q_DECLARE_METATYPE(QDockWidget*)
Q_DECLARE_METATYPE(QMainWindow*)
Q_DECLARE_METATYPE(QMdiArea*)
Q_DECLARE_METATYPE(QMdiSubWindow*)
// Q_DECLARE_METATYPE(QMenu*) // predefined
Q_DECLARE_METATYPE(QMenuBar*)
// Q_DECLARE_METATYPE(QSizeGrip*) // predefined
Q_DECLARE_METATYPE(QStatusBar*)
Q_DECLARE_METATYPE(QToolBar*)
Q_DECLARE_METATYPE(QCursor*)
Q_DECLARE_METATYPE(QPalette*)
Q_DECLARE_METATYPE(QColor*)
// Q_DECLARE_METATYPE(QColorSpace*) // Qt 5.14
// Q_DECLARE_METATYPE(QColorTransform*) // Qt 5.14
Q_DECLARE_METATYPE(QFont*)
Q_DECLARE_METATYPE(QFontDatabase*)
Q_DECLARE_METATYPE(QFontInfo*)
// Q_DECLARE_METATYPE(QGraphicsAnchor*) // predefined
// Q_DECLARE_METATYPE(QGraphicsAnchorLayout*) // predefined
Q_DECLARE_METATYPE(QCommonStyle*)
Q_DECLARE_METATYPE(QStyle*)
Q_DECLARE_METATYPE(QStyleFactory*)
Q_DECLARE_METATYPE(QStyleHintReturn*)
Q_DECLARE_METATYPE(QStyleHintReturnMask*)
Q_DECLARE_METATYPE(QStyleHintReturnVariant*)
Q_DECLARE_METATYPE(QStyleOption*)
Q_DECLARE_METATYPE(QStylePainter*)
// Q_DECLARE_METATYPE(QGraphicsAnchor*) // predefined
// Q_DECLARE_METATYPE(QGraphicsAnchorLayout*) // predefined
Q_DECLARE_METATYPE(QBoxLayout*)
Q_DECLARE_METATYPE(QHBoxLayout*)
Q_DECLARE_METATYPE(QVBoxLayout*)
Q_DECLARE_METATYPE(QFormLayout*)
Q_DECLARE_METATYPE(QGridLayout*)
Q_DECLARE_METATYPE(QLayout*)
Q_DECLARE_METATYPE(QLayoutItem*)
Q_DECLARE_METATYPE(QSpacerItem*)
Q_DECLARE_METATYPE(QWidgetItem*)
Q_DECLARE_METATYPE(QSizePolicy*)
Q_DECLARE_METATYPE(QStackedLayout*)
// Q_DECLARE_METATYPE(QButtonGroup*) // predefined
// Q_DECLARE_METATYPE(QGroupBox*) // predefined
// Q_DECLARE_METATYPE(QStackedWidget*) // predefined

__attribute__((constructor))
static void q_meta_register_widget_metatypes()
{
    qRegisterMetaType<QApplication*>();
    qRegisterMetaType<QGuiApplication*>();
    qRegisterMetaType<QCoreApplication*>();
    qRegisterMetaType<QObject*>();
    qRegisterMetaType<QWidget*>();
    qRegisterMetaType<QCheckBox*>();
    qRegisterMetaType<QComboBox*>();
    qRegisterMetaType<QCommandLinkButton*>();
    qRegisterMetaType<QDateEdit*>();
    qRegisterMetaType<QDateTimeEdit*>();
    qRegisterMetaType<QTimeEdit*>();
    qRegisterMetaType<QDial*>();
    qRegisterMetaType<QFocusFrame*>();
    qRegisterMetaType<QFontComboBox*>();
    qRegisterMetaType<QLabel*>();
    qRegisterMetaType<QLCDNumber*>();
    qRegisterMetaType<QLineEdit*>();
    qRegisterMetaType<QMenu*>();
    qRegisterMetaType<QProgressBar*>();
    qRegisterMetaType<QPushButton*>();
    qRegisterMetaType<QRadioButton*>();
    qRegisterMetaType<QScrollArea*>();
    qRegisterMetaType<QScrollBar*>();
    qRegisterMetaType<QSizeGrip*>();
    qRegisterMetaType<QSlider*>();
    qRegisterMetaType<QDoubleSpinBox*>();
    qRegisterMetaType<QSpinBox*>();
    qRegisterMetaType<QTabBar*>();
    qRegisterMetaType<QTabWidget*>();
    qRegisterMetaType<QToolBox*>();
    qRegisterMetaType<QToolButton*>();
    qRegisterMetaType<QColumnView*>();
    qRegisterMetaType<QDataWidgetMapper*>();
    qRegisterMetaType<QListView*>();
    qRegisterMetaType<QTableView*>();
    qRegisterMetaType<QTreeView*>();
    qRegisterMetaType<QUndoView*>();
    qRegisterMetaType<QCalendarWidget*>();
#ifdef Q_OS_MAC
    qRegisterMetaType<QMacCocoaViewContainer*>();
    qRegisterMetaType<QMacNativeWidget*>();
#endif
    qRegisterMetaType<QAbstractButton*>();
    qRegisterMetaType<QAbstractScrollArea*>();
    qRegisterMetaType<QAbstractSlider*>();
    qRegisterMetaType<QAbstractSpinBox*>();
    qRegisterMetaType<QFrame*>();
    qRegisterMetaType<QDialog*>();
    qRegisterMetaType<QButtonGroup*>();
    qRegisterMetaType<QGroupBox*>();
    qRegisterMetaType<QSplitter*>();
    qRegisterMetaType<QSplitterHandle*>();
    qRegisterMetaType<QStackedWidget*>();
    qRegisterMetaType<QTabWidget*>();
    qRegisterMetaType<QGraphicsEffect*>();
    qRegisterMetaType<QGraphicsAnchor*>();
    qRegisterMetaType<QGraphicsAnchorLayout*>();
    qRegisterMetaType<QGraphicsGridLayout*>();
    qRegisterMetaType<QAbstractGraphicsShapeItem*>();
    qRegisterMetaType<QGraphicsEllipseItem*>();
    qRegisterMetaType<QGraphicsItem*>();
    qRegisterMetaType<QGraphicsItemGroup*>();
    qRegisterMetaType<QGraphicsLineItem*>();
    qRegisterMetaType<QGraphicsObject*>();
    qRegisterMetaType<QGraphicsPathItem*>();
    qRegisterMetaType<QGraphicsPixmapItem*>();
    qRegisterMetaType<QGraphicsPolygonItem*>();
    qRegisterMetaType<QGraphicsRectItem*>();
    qRegisterMetaType<QGraphicsSimpleTextItem*>();
    qRegisterMetaType<QGraphicsTextItem*>();
    qRegisterMetaType<QGraphicsLayout*>();
    qRegisterMetaType<QGraphicsLayoutItem*>();
    qRegisterMetaType<QGraphicsLinearLayout*>();
    qRegisterMetaType<QGraphicsProxyWidget*>();
    qRegisterMetaType<QGraphicsScene*>();
    qRegisterMetaType<QGraphicsSceneContextMenuEvent*>();
    qRegisterMetaType<QGraphicsSceneDragDropEvent*>();
    qRegisterMetaType<QGraphicsSceneEvent*>();
    qRegisterMetaType<QGraphicsSceneHelpEvent*>();
    qRegisterMetaType<QGraphicsSceneHoverEvent*>();
    qRegisterMetaType<QGraphicsSceneMouseEvent*>();
    qRegisterMetaType<QGraphicsSceneMoveEvent*>();
    qRegisterMetaType<QGraphicsSceneResizeEvent*>();
    qRegisterMetaType<QGraphicsSceneWheelEvent*>();
    qRegisterMetaType<QGraphicsTransform*>();
    qRegisterMetaType<QGraphicsView*>();
    qRegisterMetaType<QGraphicsWidget*>();
    qRegisterMetaType<QStyleOptionGraphicsItem*>();
    // qRegisterMetaType<QGraphicsSvgItem*>(); // svg
    qRegisterMetaType<QAbstractItemModel*>();
    qRegisterMetaType<QAbstractListModel*>();
    qRegisterMetaType<QAbstractTableModel*>();
    qRegisterMetaType<QModelIndex*>();
    qRegisterMetaType<QPersistentModelIndex*>();
    qRegisterMetaType<QAbstractProxyModel*>();
    // qRegisterMetaType<QConcatenateTablesProxyModel*>(); // Qt 5.13
    qRegisterMetaType<QIdentityProxyModel*>();
    qRegisterMetaType<QItemSelection*>();
    qRegisterMetaType<QItemSelectionModel*>();
    qRegisterMetaType<QItemSelectionRange*>();
    qRegisterMetaType<QSortFilterProxyModel*>();
    qRegisterMetaType<QStringListModel*>();
    qRegisterMetaType<QStandardItem*>();
    qRegisterMetaType<QStandardItemModel*>();
    qRegisterMetaType<QAbstractItemDelegate*>();
    qRegisterMetaType<QAbstractItemView*>();
    qRegisterMetaType<QColumnView*>();
    qRegisterMetaType<QDataWidgetMapper*>();
    qRegisterMetaType<QHeaderView*>();
    qRegisterMetaType<QItemDelegate*>();
    // qRegisterMetaType<QItemEditorCreator*>(); // requires template arguments
    // qRegisterMetaType<QItemEditorCreatorBase*>(); // requires template arguments
    qRegisterMetaType<QItemEditorFactory*>();
    // qRegisterMetaType<QStandardItemEditorCreator*>(); // requires template arguments
    qRegisterMetaType<QListView*>();
    qRegisterMetaType<QListWidget*>();
    qRegisterMetaType<QListWidgetItem*>();
    qRegisterMetaType<QStyledItemDelegate*>();
    qRegisterMetaType<QTableView*>();
    qRegisterMetaType<QTableWidget*>();
    qRegisterMetaType<QTableWidgetItem*>();
    qRegisterMetaType<QTableWidgetSelectionRange*>();
    qRegisterMetaType<QTreeView*>();
    qRegisterMetaType<QTreeWidget*>();
    qRegisterMetaType<QTreeWidgetItem*>();
    qRegisterMetaType<QTreeWidgetItemIterator*>();
    qRegisterMetaType<QFileSystemModel*>();
    qRegisterMetaType<QAction*>();
    qRegisterMetaType<QActionGroup*>();
    qRegisterMetaType<QWidgetAction*>();
    qRegisterMetaType<QDockWidget*>();
    qRegisterMetaType<QMainWindow*>();
    qRegisterMetaType<QMdiArea*>();
    qRegisterMetaType<QMdiSubWindow*>();
    qRegisterMetaType<QMenu*>();
    qRegisterMetaType<QMenuBar*>();
    qRegisterMetaType<QSizeGrip*>();
    qRegisterMetaType<QStatusBar*>();
    qRegisterMetaType<QToolBar*>();
    qRegisterMetaType<QCursor*>();
    qRegisterMetaType<QPalette*>();
    qRegisterMetaType<QColor*>();
    // qRegisterMetaType<QColorSpace*>(); // Qt 5.14
    // qRegisterMetaType<QColorTransform*>(); // Qt 5.14
    qRegisterMetaType<QFont*>();
    qRegisterMetaType<QFontDatabase*>();
    qRegisterMetaType<QFontInfo*>();
    qRegisterMetaType<QGraphicsAnchor*>();
    qRegisterMetaType<QGraphicsAnchorLayout*>();
    qRegisterMetaType<QCommonStyle*>();
    qRegisterMetaType<QStyle*>();
    qRegisterMetaType<QStyleFactory*>();
    qRegisterMetaType<QStyleHintReturn*>();
    qRegisterMetaType<QStyleHintReturnMask*>();
    qRegisterMetaType<QStyleHintReturnVariant*>();
    qRegisterMetaType<QStyleOption*>();
    qRegisterMetaType<QStylePainter*>();
    qRegisterMetaType<QGraphicsAnchor*>();
    qRegisterMetaType<QGraphicsAnchorLayout*>();
    qRegisterMetaType<QBoxLayout*>();
    qRegisterMetaType<QHBoxLayout*>();
    qRegisterMetaType<QVBoxLayout*>();
    qRegisterMetaType<QFormLayout*>();
    qRegisterMetaType<QGridLayout*>();
    qRegisterMetaType<QLayout*>();
    qRegisterMetaType<QLayoutItem*>();
    qRegisterMetaType<QSpacerItem*>();
    qRegisterMetaType<QWidgetItem*>();
    qRegisterMetaType<QSizePolicy*>();
    qRegisterMetaType<QStackedLayout*>();
    qRegisterMetaType<QButtonGroup*>();
    qRegisterMetaType<QGroupBox*>();
}

/*
 * QMetaType
 */

extern "C" Q_DECL_EXPORT
int q_meta_type_type(const char *name)
{
    return QMetaType::type(name);
}

extern "C" Q_DECL_EXPORT
const QMetaObject *q_meta_type_meta_object_for_type(int type)
{
    return QMetaType::metaObjectForType(type);
}

extern "C" Q_DECL_EXPORT
const char *q_meta_type_type_name(int type)
{
    return QMetaType::typeName(type);
}

/*
 * QMetaObject
 */

extern "C" Q_DECL_EXPORT
const char* q_meta_object_class_name(QMetaObject* mo)
{
    return mo->className();
}

extern "C" Q_DECL_EXPORT
const QMetaObject* q_meta_object_super_class(QMetaObject* mo)
{
    return mo->superClass();
}

extern "C" Q_DECL_EXPORT
const QMetaMethod *q_meta_object_method(QMetaObject *mo, int index)
{
    return new QMetaMethod(mo->method(index));
}

extern "C" Q_DECL_EXPORT
int q_meta_object_method_count(QMetaObject *mo)
{
    return mo->methodCount();
}

extern "C" Q_DECL_EXPORT
int q_meta_object_method_offset(QMetaObject *mo)
{
    return mo->methodOffset();
}

extern "C" Q_DECL_EXPORT
int q_meta_object_index_of_method(QMetaObject *mo, const char *name)
{
    return mo->indexOfMethod(name);
}

extern "C" Q_DECL_EXPORT
const QMetaMethod *q_meta_object_constructor(QMetaObject *mo, int index)
{
    return new QMetaMethod(mo->constructor(index));
}

extern "C" Q_DECL_EXPORT
int q_meta_object_constructor_count(QMetaObject *mo)
{
    return mo->constructorCount();
}

extern "C" Q_DECL_EXPORT
int q_meta_object_index_of_constructor(QMetaObject *mo, const char *name)
{
    return mo->indexOfConstructor(name);
}

extern "C" Q_DECL_EXPORT
const QMetaProperty *q_meta_object_property(QMetaObject *mo, int index)
{
    return new QMetaProperty(mo->property(index));
}

extern "C" Q_DECL_EXPORT
int q_meta_object_property_count(QMetaObject *mo)
{
    return mo->propertyCount();
}

extern "C" Q_DECL_EXPORT
int q_meta_object_property_offset(QMetaObject *mo)
{
    return mo->propertyOffset();
}

extern "C" Q_DECL_EXPORT
int q_meta_object_index_of_property(QMetaObject *mo, const char *name)
{
    return mo->indexOfProperty(name);
}

extern "C" Q_DECL_EXPORT
QObject *q_meta_object_new_instance(QMetaObject *mo,
                                    int argc,
                                    const char *types[],
                                    const void *data[])
{
    QGenericArgument arg0(argc > 0 ? types[0] : nullptr, argc > 0 ? data[0] : nullptr);
    QGenericArgument arg1(argc > 1 ? types[1] : nullptr, argc > 1 ? data[1] : nullptr);
    QGenericArgument arg2(argc > 2 ? types[2] : nullptr, argc > 2 ? data[2] : nullptr);
    QGenericArgument arg3(argc > 3 ? types[3] : nullptr, argc > 3 ? data[3] : nullptr);
    QGenericArgument arg4(argc > 4 ? types[4] : nullptr, argc > 4 ? data[4] : nullptr);
    QGenericArgument arg5(argc > 5 ? types[5] : nullptr, argc > 5 ? data[5] : nullptr);
    QGenericArgument arg6(argc > 6 ? types[6] : nullptr, argc > 6 ? data[6] : nullptr);
    QGenericArgument arg7(argc > 7 ? types[7] : nullptr, argc > 7 ? data[7] : nullptr);
    QGenericArgument arg8(argc > 8 ? types[8] : nullptr, argc > 8 ? data[8] : nullptr);
    QGenericArgument arg9(argc > 9 ? types[9] : nullptr, argc > 9 ? data[9] : nullptr);

    return mo->newInstance(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

extern "C" Q_DECL_EXPORT
int q_meta_object_invoke_method(QObject *obj,
                                const char *member,
                                Qt::ConnectionType mode,
                                const char *return_type_name,
                                void *return_data,
                                int argc,
                                const char *types[],
                                const void *data[])
{
    QGenericReturnArgument ret{return_type_name, return_data};
    QGenericArgument arg0(argc > 0 ? types[0] : nullptr, argc > 0 ? data[0] : nullptr);
    QGenericArgument arg1(argc > 1 ? types[1] : nullptr, argc > 1 ? data[1] : nullptr);
    QGenericArgument arg2(argc > 2 ? types[2] : nullptr, argc > 2 ? data[2] : nullptr);
    QGenericArgument arg3(argc > 3 ? types[3] : nullptr, argc > 3 ? data[3] : nullptr);
    QGenericArgument arg4(argc > 4 ? types[4] : nullptr, argc > 4 ? data[4] : nullptr);
    QGenericArgument arg5(argc > 5 ? types[5] : nullptr, argc > 5 ? data[5] : nullptr);
    QGenericArgument arg6(argc > 6 ? types[6] : nullptr, argc > 6 ? data[6] : nullptr);
    QGenericArgument arg7(argc > 7 ? types[7] : nullptr, argc > 7 ? data[7] : nullptr);
    QGenericArgument arg8(argc > 8 ? types[8] : nullptr, argc > 8 ? data[8] : nullptr);
    QGenericArgument arg9(argc > 9 ? types[9] : nullptr, argc > 9 ? data[9] : nullptr);

    return QMetaObject::invokeMethod(obj, member, mode, ret,
                                     arg0, arg1, arg2, arg3, arg4,
                                     arg5, arg6, arg7, arg8, arg9);
}

/*
 *  QMetaMethod
 */

extern "C" Q_DECL_EXPORT
const char *q_meta_method_method_signature(QMetaMethod *mm)
{
    return mm->methodSignature();
}

/*
 * QMetaProperty
 */

extern "C" Q_DECL_EXPORT
const char *q_meta_property_name(QMetaProperty *mp)
{
    return mp->name();
}
