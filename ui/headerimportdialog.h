#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QCheckBox>
#include "uitypes.h"

/*!

    \ingroup uiapi
*/
class BINARYNINJAUIAPI HeaderImportDialog : public QDialog
{
	Q_OBJECT
	QLineEdit* m_fileEdit;
	QPushButton* m_browseButton;
	QTextEdit* m_compilerFlagsEdit;
	QSplitter* m_splitter;
	QWidget* m_resultsWidget;
	QLayout* m_resultsLayout;
	QTextBrowser* m_compilerErrorsText;
	QTreeWidget* m_typesTree;
	QCheckBox* m_includeSystemTypesCheck;
	QCheckBox* m_builtinMacrosCheck;
	QPushButton* m_previewButton;
	QPushButton* m_importButton;
	BinaryViewRef m_data;

	std::string m_filePath;
	BinaryNinja::TypeParserResult m_result;
	std::vector<BinaryNinja::TypeParserError> m_errors;

protected Q_SLOTS:
	void browseFile();
	void updateButtons();
	void previewTypes();
	void importTypes();

protected:
	virtual void keyPressEvent(QKeyEvent* event) override;

private:
	bool loadTypes();
	bool isExistingType(const BinaryNinja::QualifiedName& name) const;
	bool isBuiltinType(const BinaryNinja::QualifiedName& name) const;

public:
	HeaderImportDialog(QWidget* parent, BinaryViewRef view);
	~HeaderImportDialog() = default;
};
